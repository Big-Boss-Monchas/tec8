#include <GL/glut.h>
#include <iostream>
#define border 5

void quadrantFirst(int, int, int, int);
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
	quadrantFirst(0 + border,0 + border, x + border, y + border);
	glutMainLoop();
}

void quadrantFirst(int x_start, int y_start, int x_end, int y_end)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(x_end + x_start, y_end + y_start); // Establece el tamaño de la ventana
	glutCreateWindow("First Quadrant Window");
	initiate(x_end, y_end);
	glutDisplayFunc(mainLines);
}

void initiate(int x_end, int y_end)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, x_end + border, 0.0, y_end + border);
}

void mainLines(void)
{
	int spacing = x / 20;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(border, border);
	glVertex2i(x + border, border);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(border, border);
	glVertex2i(border, y + border);
	glEnd();
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
	int x1 = border + spacing, y1 = border + spacing;
	while (x1 < x)
	{
		glVertex2i(x1, border);
		glVertex2i(x1, y + border);
		x1 += spacing;
	}
	while (y1 < y)
	{
		glVertex2i(border, y1);
		glVertex2i(x + border, y1);
		y1 += spacing;
	}
	glEnd();
	glFlush();
}
