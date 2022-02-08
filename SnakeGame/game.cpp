#include <GL/freeglut.h>
#include "game.h"

int gridX, gridY;

void initGrid(int x, int y) {
	gridX = x;
	gridY = y;
}

void drawGrid() {
	for (int x = 0; x < gridX; x++) {
		for (int y = 0; y < gridY; y++) {
			unit(x, y);
		}
	}
}

// Square unit, xy는 좌측하단을 의미 (x,y) (x+1,y) (x+1,y+1) (x, y+1) 순서로 그리는 LOOP
void unit(int x, int y) {
	if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1) {
		glLineWidth(3.0); // 선의 두께
		glColor3f(1.0, 0.0, 0.0);
	}
	else {
		glLineWidth(1.0); // 선의 두께
		glColor3f(1.0, 1.0, 1.0); // white color
	}
	// value Set
	
	

	glBegin(GL_LINE_LOOP);
		glVertex2f(x, y);
		glVertex2f(x + 1, y);
		glVertex2f(x + 1, y + 1);
		glVertex2f(x, y + 1);
	glEnd();
}