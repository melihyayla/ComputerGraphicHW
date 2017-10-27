#include <GL\glew.h>
#include <iostream>
#include <GL\freeglut.h>

void init2D(float r, float g, float b) {

	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0, 500.0, 0.0, 450.0);
}

void column(int x,int y) {

	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x, y+150);
	glVertex2i(x+30, y+150);
	glVertex2i(x+30, y);
	glEnd();
}

void row1(int x, int y) {

	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x+20, y );
	glVertex2i(x+20, y +50);
	glVertex2i(x , y+50);
	glEnd();
}

void row2(int x, int y) {

	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + 30, y);
	glVertex2i(x + 30, y + 30);
	glVertex2i(x, y + 30);
	glEnd();
}

void row3(int x, int y) {

	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + 40, y);
	glVertex2i(x + 40, y + 15);
	glVertex2i(x, y + 15);
	glEnd();
}
void slash1(int x, int y) {
	glBegin(GL_POLYGON);

	glVertex2i(x, y);
	glVertex2i(x+30, y+50);
	glVertex2i(x+60, y+50);
	glVertex2i(x, y-50);

	glEnd();
}

void slash2(int x, int y) {
	glBegin(GL_POLYGON);

	glVertex2i(x, y);
	glVertex2i(x + 60, y-100);
	glVertex2i(x + 30, y-100);
	glVertex2i(x, y - 50);

	glEnd();

	
}



void displayH() {
	
	column(110, 100);
	row3(105, 100);
	row3(105, 250);
	row1(140, 150);
	column(160, 100);
	row3(155, 100);
	row3(155, 250);
}

void displayK() {
	column(200,100);
	row3(195, 100);
	row3(195, 250);
	slash1(230, 200);
	row3(255, 250);
	slash2(230, 200);
	row3(255, 100);
}


void displayU() {

	column(300, 100);
	row3(295, 100);
	row3(295, 250);
	row2(330, 100);
	
	column(360, 100);
	row3(355, 100);
	row3(355, 250);

}

void display(void) {

	
	glClear(GL_COLOR_BUFFER_BIT);
	
	/*
	glColor3f(0.6f, 0.6f, 0.6f);

	glBegin(GL_POLYGON);
	glVertex2i(76, 76);
	glVertex2i(76, 324);
	glVertex2i(424, 324);
	glVertex2i(424, 76);
	glEnd();
	*/

	glColor3f(0.9f, 0.1f, 0.1f);

	glBegin(GL_LINES);
	glVertex2i(75, 75);
	glVertex2i(75, 325);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.9f);
	glBegin(GL_LINES);
	glVertex2i(75, 325);
	glVertex2i(425, 325);
	glEnd();

	glColor3f(0.9f, 0.1f, 0.1f);
	glBegin(GL_LINES);
	glVertex2i(425, 325);
	glVertex2i(425, 75);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.9f);
	glBegin(GL_LINES);
	glVertex2i(425, 75);
	glVertex2i(75, 75);
	glEnd();

	glColor3f(0.0f, 0.6f, 0.6f);

	displayU();

	glColor3f(0.3f, 0.3f, 0.8f);

	displayK();
	
	glColor3f(0.9f, 0.2f, 0.2f);
	
	displayH();

	glFlush();

}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(250,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("deneme");
	init2D(0.0, 0.0, 0.0);
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;


}