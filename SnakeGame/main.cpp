#include <GL/freeglut.h>
#include "game.h"
#include <stdlib.h>

#define COLUMNS 40
#define ROWS 40
#define FPS 10
float fps = 10;

extern short sDirection;
bool gameOver = false;

int score = 0;

void display_callback();
void reshape_callback(int, int);
void timer_callback(int);
void keyboard_callback(int, int, int);

void init() {
	// 0.0~ 1.0의 RGBA값 입력하여 배경값 조절
	glClearColor(0.0, 0.0, 0.0, 1.0);
	initGrid(COLUMNS, ROWS);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Snake");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback); // 창 크기가 바뀔때마다 호출
	glutTimerFunc(0, timer_callback, 0);
	//glutKeyboardFunc(); // 키입력, 마우스 포지션을 입력받음
	glutSpecialFunc(keyboard_callback);
	init();
	glutMainLoop();
	return 0;
}

int index = 0;
void display_callback() {
	// color buffer clear
	// 이걸 해야 배경색이 적용됨
	fps += 0.01;
	glClear(GL_COLOR_BUFFER_BIT); 
	drawGrid();
	drawSnake();
	drawFood();
	glutSwapBuffers(); // 더블버퍼 모드에서 버퍼 스왑 수행
	if (gameOver) {
		char _score[5];
		_itoa_s(score, _score, 5);
		char text[50] = "Your Score : ";
		strcat_s(text, _score);
		MessageBox(NULL, text, "GameOver", 0);
		exit(0);
	}
}

// argu : resize된 창의 size
void reshape_callback(int w, int h) {
	// x, y -> 시작점(좌측상단), w,h -> new사이즈
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//2d 시스템의 x축과 y축
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int) {
	glutPostRedisplay(); // FPS 설정
	glutTimerFunc(1000 / fps, timer_callback, 0);
}
void keyboard_callback(int key, int, int) {
	switch (key) {
	case GLUT_KEY_UP:
		if (sDirection != DOWN)
			sDirection = UP;
		break;
	case GLUT_KEY_DOWN:
		if (sDirection != UP)
			sDirection = DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if (sDirection != LEFT)
			sDirection = RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (sDirection != RIGHT)
			sDirection = LEFT;
		break;
	}
}