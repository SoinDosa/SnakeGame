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
	// 0.0~ 1.0�� RGBA�� �Է��Ͽ� ��氪 ����
	glClearColor(0.0, 0.0, 0.0, 1.0);
	initGrid(COLUMNS, ROWS);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Snake");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback); // â ũ�Ⱑ �ٲ𶧸��� ȣ��
	glutTimerFunc(0, timer_callback, 0);
	//glutKeyboardFunc(); // Ű�Է�, ���콺 �������� �Է¹���
	glutSpecialFunc(keyboard_callback);
	init();
	glutMainLoop();
	return 0;
}

int index = 0;
void display_callback() {
	// color buffer clear
	// �̰� �ؾ� ������ �����
	fps += 0.01;
	glClear(GL_COLOR_BUFFER_BIT); 
	drawGrid();
	drawSnake();
	drawFood();
	glutSwapBuffers(); // ������� ��忡�� ���� ���� ����
	if (gameOver) {
		char _score[5];
		_itoa_s(score, _score, 5);
		char text[50] = "Your Score : ";
		strcat_s(text, _score);
		MessageBox(NULL, text, "GameOver", 0);
		exit(0);
	}
}

// argu : resize�� â�� size
void reshape_callback(int w, int h) {
	// x, y -> ������(�������), w,h -> new������
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//2d �ý����� x��� y��
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int) {
	glutPostRedisplay(); // FPS ����
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