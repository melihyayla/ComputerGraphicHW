#include <GL\glew.h>
#include <iostream>
#include <GL\freeglut.h>
using namespace std;
#include <iostream>

void init2D(float r, float g, float b) {

	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void calculateP(int n, int xi[], int yi[], int zi[], int ti[]) {

	int* a1 = new int[n];
	int* b1 = new int[n];
	int* c1 = new int[n];
	int* d1 = new int[n];

	int* a2 = new int[n];
	int* b2 = new int[n];
	int* c2 = new int[n];
	int* d2 = new int[n];


	//First point [a1[0],a2[0]], a1[0] = xa , a2[0] =ya . 

	a1[0] = (xi[0] + yi[0]) / 2;
	a2[0] = (xi[1] + yi[1]) / 2;

	//Second point [b1[0],b2[0]], b1[0] = xb , b2[0] =yb . 
	b1[0] = (yi[0] + zi[0]) / 2;
	b2[0] = (yi[1] + zi[1]) / 2;

	//Third point [c1[0],c2[0]], c1[0] = xc , c2[0] =yc . 	
	c1[0] = (zi[0] + ti[0]) / 2;
	c2[0] = (zi[1] + ti[1]) / 2;

	//Third point [d1[0],d2[0]], d1[0] = xd , c2[0] =yd . 
	d1[0] = (xi[0] + ti[0]) / 2;
	d2[0] = (xi[1] + ti[1]) / 2;

	for (int i = 1; i < n + 1; i++) {

		a1[i] = (a1[i - 1] + b1[i - 1]) / 2;
		a2[i] = (a2[i - 1] + b2[i - 1]) / 2;

		b1[i] = (b1[i - 1] + c1[i - 1]) / 2;
		b2[i] = (b2[i - 1] + c2[i - 1]) / 2;

		c1[i] = (c1[i - 1] + d1[i - 1]) / 2;
		c2[i] = (c2[i - 1] + d2[i - 1]) / 2;

		d1[i] = (d1[i - 1] + a1[i - 1]) / 2;
		d2[i] = (d2[i - 1] + a2[i - 1]) / 2;
	}

	glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	glBegin(GL_POLYGON);

	glVertex2i(xi[0], xi[1]);
	glVertex2i(yi[0], yi[1]);
	glVertex2i(zi[0], zi[1]);
	glVertex2i(ti[0], ti[1]);

	glEnd();

	float* r1 = new float[n];
	float* r2 = new float[n];
	float* r3 = new float[n];

	r1[0] = ((float)rand()) / (float)RAND_MAX;
	r2[0] = ((float)rand()) / (float)RAND_MAX;
	r3[0] = ((float)rand()) / (float)RAND_MAX;

	for (int i = 0; i < n; i++) {
		
			r1[i+1] = ((float)rand()) / (float)RAND_MAX;
			r2[i+1] = ((float)rand()) / (float)RAND_MAX;
			r3[i+1] = ((float)rand()) / (float)RAND_MAX;

		if(r1[i+1]!=r1[i] && r2[i+1] != r2[i] && r3[i+1] != r2[i])
		glColor3f(r1[i], r2[i], r3[i]);
		else {
			r1[i + 1] = ((float)rand()) / (float)RAND_MAX;
			r2[i + 1] = ((float)rand()) / (float)RAND_MAX;
			r3[i + 1] = ((float)rand()) / (float)RAND_MAX;
		glColor3f(r1[i], r2[i], r3[i]);
		}


		glBegin(GL_POLYGON);
		glVertex2i(a1[i], a2[i]);
		glVertex2i(b1[i], b2[i]);
		glVertex2i(c1[i], c2[i]);
		glVertex2i(d1[i], d2[i]);
		glEnd();

	}


}


void display(void) {


	int x[] = { 100,100 };
	int y[] = { 100,900 };
	int z[] = { 900,900 };
	int t[] = { 900,100 };

	glClear(GL_COLOR_BUFFER_BIT);


	glColor3f(0.9f, 0.1f, 0.1f);

	int n;
	while (true) {

		cout << " Enter a value ";
		cin >> n;
		if (n == 0) {
			glColor3f(1.0f, 1.0f, 1.0f);
			glRecti(100, 100, 900, 900);
		}
		else
			calculateP(n - 1, x, y, z, t);
		glFlush();
	}


}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(250, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("deneme");
	init2D(0.0, 0.0, 0.0);
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;


}