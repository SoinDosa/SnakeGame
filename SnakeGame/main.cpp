#include <GL/freeglut.h>

void display_callback();
void reshape_callback(int, int);

void init() {
	// 0.0~ 1.0�� RGBA�� �Է��Ͽ� ��氪 ����
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Snake");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback); // â ũ�Ⱑ �ٲ𶧸��� ȣ��
	init();
	glutMainLoop();
	return 0;
}

void display_callback() {
	// color buffer clear
	// �̰� �ؾ� ������ �����
	glClear(GL_COLOR_BUFFER_BIT); 
	
	glutSwapBuffers();
}

// argu : resize�� â�� size
void reshape_callback(int w, int h) {
	// x, y -> ������(�������), w,h -> new������
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//2d �ý����� x��� y��
	glOrtho(0.0, 40.0, 0.0, 40.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}