#include <GL/freeglut.h>

void display_callback();
void reshape_callback(int, int);

void init() {
	// 0.0~ 1.0의 RGBA값 입력하여 배경값 조절
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Snake");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback); // 창 크기가 바뀔때마다 호출
	init();
	glutMainLoop();
	return 0;
}

void display_callback() {
	// color buffer clear
	// 이걸 해야 배경색이 적용됨
	glClear(GL_COLOR_BUFFER_BIT); 
	
	glutSwapBuffers();
}

// argu : resize된 창의 size
void reshape_callback(int w, int h) {
	// x, y -> 시작점(좌측상단), w,h -> new사이즈
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//2d 시스템의 x축과 y축
	glOrtho(0.0, 40.0, 0.0, 40.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}