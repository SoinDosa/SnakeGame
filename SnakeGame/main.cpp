#include <GL/freeglut.h>

void display_callback();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Snake");
	glutDisplayFunc(display_callback);
	glutMainLoop();
	return 0;
}

void display_callback() {
	glutSwapBuffers();
}