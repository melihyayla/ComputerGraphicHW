#include <GL/glut.h>

GLsizei winWidth = 1250, winHeight = 450;    // Initial display window size.
GLint xRaster = 175, yRaster = 100;          // Initialize raster position. 



GLubyte hour[38] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
'9',  '1', '0',  '1', '1',  '1', '2' ,  '1', '3',  '1', '4',  '1', '5',  '1', '6',  '1', '7',  '1', '8',
'1', '9',  '2', '0', '2', '1',  '2', '2',  '2' , '3' };



GLubyte tempVV[11] = { '0', '2','4', '6', '8', '1' ,'0', '1', '2','°','C' };

GLint dataValue[24] = { 120, 120, 160, 160, 200, 160, 200, 200, 200, 240, 240, 280, 360, 360, 320, 280, 280, 240, 240, 200,
160, 200, 120, 120 };





void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);    // White display window.
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}

void barChart(void)
{
	GLint month, k;

	GLint hours, x;

	glClear(GL_COLOR_BUFFER_BIT); //  Clear display window.

	int myY = 100;
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i <10; i++) {
		glRasterPos2i(5, myY);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, tempVV[i]);

		if (i == 5 || i == 7 || i == 9) {
			i += 1;
			glRasterPos2i(11, myY);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, tempVV[i]);
		}
		myY += 42;
	}

	glBegin(GL_LINES);
	glVertex2i(20, 100);
	glVertex2i(20, 390);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(10, 390);
	glVertex2i(30, 390);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(20, 100);
	glVertex2i(1210, 100);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(1210, 120);
	glVertex2i(1210, 80);
	glEnd();

	for (k = 0; k < 24; k++) {

		if (k<6 || k>18)
			glColor3f(0.0, 0.0, 1.0);
		else
			glColor3f(0.9, 0.7, 0.0);

		glRecti(25 + k * 50, 100, 40 + k * 50, dataValue[k]);

	}

	glColor3f(1.0, 0.0, 0.0);           
	xRaster = 22;                   

	for (int j = 0; j < 10; j++) {
		glRasterPos2i(xRaster, 80);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hour[j]);
		xRaster += 51;
	}

	for (int j = 0; j <28; j++) {
		glRasterPos2i(xRaster, 80);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hour[j + 10]);
		j += 1;
		xRaster += 7;
		glRasterPos2i(xRaster, 80);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hour[j + 10]);

		xRaster += 40;
		if (j >= 11 && j <18)
			xRaster += 7;
	}

	glRasterPos2i(xRaster - 4, 90);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');
	glRasterPos2i(xRaster + 8, 95);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, '1');
	glRasterPos2i(xRaster + 14, 95);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, '/');
	glRasterPos2i(xRaster + 18, 95);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, '2');
	glRasterPos2i(xRaster + 24, 95);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, '4');


	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));

	glClear(GL_COLOR_BUFFER_BIT);
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Bar Chart of Temperature");

	init();
	glutDisplayFunc(barChart);
	glutReshapeFunc(winReshapeFcn);

	glutMainLoop();
}
