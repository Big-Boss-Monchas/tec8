#include <iostream>
#include "Shapes.h"
#include <GL/glut.h>

void quadrantFour(int, int, int, int);
void initiate(int, int);
void mainLines(void);

int x, y;

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	std::cout << "Please enter width size:";
	std::cin >> x;
	std::cout << "Please enter height size:";
	std::cin >> y;
	quadrantFour(0, 0, x, y);
	glutMainLoop();
}

void quadrantFour(int x_start, int y_start, int x_end, int y_end)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(x_end + x_start, y_end + y_start); // Establece el tamaño de la ventana
	glutCreateWindow("Four Quadrant Window");
	initiate(x_end, y_end);
	glutDisplayFunc(mainLines);
}

void initiate(int x_end, int y_end)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-(x_end / 2), x_end / 2, -(y_end / 2), y_end / 2);
}

void mainLines(void)
{
	int x_center = (int)x / 2, y_center = (int)y / 2, spacing = 20;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
	int x1 = 0 + spacing, x2 = 0 - spacing;
	int y1 = 0 + spacing, y2 = 0 - spacing;
	while (x1 < x / 2)
	{
		glVertex2i(x1, -y_center);
		glVertex2i(x1, y_center);
		glVertex2i(x2, -y_center);
		glVertex2i(x2, y_center);
		x1 += spacing;
		x2 -= spacing;
	}
	while (y1 < y / 2)
	{
		glVertex2i(-x_center, y1);
		glVertex2i(x_center, y1);
		glVertex2i(-x_center, y2);
		glVertex2i(x_center, y2);
		y1 += spacing;
		y2 -= spacing;
	}
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(0, 0);
	glVertex2i(x_center, 0);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(0, 0);
	glVertex2i(0, y_center);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2i(0, 0);
	glVertex2i(-x_center, 0);
	glEnd();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(0, 0);
	glVertex2i(0, -y_center);
	glEnd();

	Rectangle rec(40, 20, 20, 20, 0.0, 1.0, 1.0, 5);
	rec.drawShape();

	glFlush();
}
