#include "Shapes.h"
#include <GL/glut.h>

// ------- CONSTRUCTORES SOBRECARGADOS -----------------------
// DE CREARSE EL OBJETO VACIO, AUTOMATICAMENTE SON ASIGNADOS
// LOS VALORES FALTANTES, DEL MISMO MODO CON LOS OTROS 
// CONSTRUCTORES QUE NO SE ENVIAN LOS PARAMETROS COMPLETOS ---
Rectangle::Rectangle() {
	setPosition(0, 0);
	setColor(1.0, 1.0, 1.0);
	setLineWidth(1);
	setBase(50);
	setHeight(25);
	setArea();
	setPerimeter();
}

Rectangle::Rectangle(int x, int y) {
	setPosition(x, y);
	setColor(1.0, 1.0, 1.0);
	setLineWidth(1);
	setBase(50);
	setHeight(25);
	setArea();
	setPerimeter();
}

Rectangle::Rectangle(int x, int y, int ba, int h) {
	setPosition(x, y);
	setColor(1.0, 1.0, 1.0);
	setLineWidth(1);
	setBase(ba);
	setHeight(h);
	setArea();
	setPerimeter();
}

Rectangle::Rectangle(int x, int y, int ba, int h, float r, float g, float b) {
	setPosition(x, y);
	setColor(r, g, b);
	setLineWidth(1);
	setBase(ba);
	setHeight(h);
	setArea();
	setPerimeter();
}

Rectangle::Rectangle(int x, int y, int ba, int h, float r, float g, float b, int lwidth) {
	setPosition(x, y);
	setColor(r, g, b);
	setLineWidth(lwidth);
	setBase(ba);
	setHeight(h);
	setArea();
	setPerimeter();
}

// ------- METODOS IMPLEMENTADOS DE LOS SETTERS --------------
// SI ALGUNOS VALORES IMPORTANTES QUE PUDIESEN AFECTAR EL
// FUNCIONAMIENTO DEL SET NO CONOCEN LOS REQUISITOS
// NECESARIOS, SON ASIGNADOS VALORES PREDEFINIDOS ------------
void Rectangle::setPosition(int x, int y) {
	point.position_x = x;
	point.position_y = y;
}

void Rectangle::setColor(float r, float g, float b) {
	if ((r >= 0 && r <= 1) && (g >= 0 && g <= 1) && (b >= 0 && b <= 1))
	{
		color.colorR = r;
		color.colorG = g;
		color.colorB = b;
	}
	else
	{
		color.colorR = 1.0;
		color.colorG = 1.0;
		color.colorB = 1.0;
	}
}

void Rectangle::setLineWidth(int width) { 
	if (width > 0) lineWidth = width; 
	else lineWidth = 1;
}

void Rectangle::setArea(void) { area = calculateArea(); }

void Rectangle::setPerimeter(void) { perimeter = calculatePerimeter(); }

void Rectangle::setBase(int b) { 
	if (b > 0) { base = b; }
	else { base = 50; }
}

void Rectangle::setHeight(int h) { 
	if (h > 0) { height = h; }
	else { height = 25; }
}

// ------- METODO PARA REALIZAR EL TRAZO DE LA FIGURA --------
// UNA VEZ LLAMADO EL METODO DRAWSHAPE, TOMA LOS COLORES Y LA
// POSICION ASIGNADOS AL OBJETO RECTANGLE, SE ASIGNAN LAS 
// COORDENADAS NECESARIAS PARA LOS VERTICES Y SE ESPECIFICA
// EL ANCHO DE LINEA; FINALMENTE SE PINTA EL RECTANGULO ------
void Rectangle::drawShape() {
	Color aux_color = getColor();
	Position aux_pos = getPosition();
	int x1 = aux_pos.position_x, y1 = aux_pos.position_y;
	int x2 = aux_pos.position_x + getBase(), y2 = aux_pos.position_y + getHeight();
	glColor3f(aux_color.colorR, aux_color.colorG, aux_color.colorB);
	glLineWidth(getLineWidth());
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x1, y2);
	glVertex2i(x1, y2);
	glVertex2i(x2, y2);
	glVertex2i(x2, y2);
	glVertex2i(x2, y1);
	glVertex2i(x2, y1);
	glVertex2i(x1, y1);
	glEnd();
}

