#include <GL/glut.h>
#include <iostream>

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
	gluOrtho2D(0.0, x_end, 0.0, y_end);
}

void mainLines(void)
{
  int x_center = (int) x / 2, y_center = (int) y / 2, spacing = 20;
	glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
	int x1 = x_center + spacing, x2 = x_center - spacing;
  int y1 = y_center + spacing, y2 = y_center - spacing;
	while (x1 < x)
	{
		glVertex2i(x1, 0);
		glVertex2i(x1, y);
    glVertex2i(x2, 0);
		glVertex2i(x2, y);
		x1 += spacing;
    x2 -= spacing;
	}
	while (y1 < y)
	{
		glVertex2i(0, y1);
		glVertex2i(x, y1);
    glVertex2i(0, y2);
		glVertex2i(x, y2);
		y1 += spacing;
    y2 -= spacing;
	}
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x_center, y_center);
	glVertex2i(x, y_center);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x_center, y_center);
	glVertex2i(x_center, y);
	glEnd();
  glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2i(x_center, y_center);
	glVertex2i(0, y_center);
	glEnd();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x_center, y_center);
	glVertex2i(x_center, 0);
	glEnd();
	glFlush();
}
