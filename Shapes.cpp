#include "Shapes.h"
#include <GL/glut.h>

// --------------- Rectangulos -------------------------------
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

// --------------- Cuadrado ----------------------------------
Square::Square() {
	setPosition(0, 0);
	setColor(1.0, 1.0, 1.0);
	setLineWidth(1);
	setSide(50);
	setArea();
	setPerimeter();
}

Square::Square(int x, int y) {
	setPosition(x, y);
	setColor(1.0, 1.0, 1.0);
	setLineWidth(1);
	setSide(50);
	setArea();
	setPerimeter();
}

Square::Square(int x, int y, int s) {
	setPosition(x, y);
	setColor(1.0, 1.0, 1.0);
	setLineWidth(1);
	setSide(s);
	setArea();
	setPerimeter();
}

Square::Square(int x, int y, int s, float r, float g, float b) {
	setPosition(x, y);
	setColor(r, g, b);
	setLineWidth(1);
	setSide(s);
	setArea();
	setPerimeter();
}

Square::Square(int x, int y, int s, float r, float g, float b, int lwidth) {
	setPosition(x, y);
	setColor(r, g, b);
	setLineWidth(lwidth);
	setSide(s);
	setArea();
	setPerimeter();
}

// ------- METODOS IMPLEMENTADOS DE LOS SETTERS --------------
void Square::setSide(int s) {
	if (s > 0) { side = s; }
	else { side = 50; }
}

// ------- METODO PARA REALIZAR EL TRAZO DE LA FIGURA --------
void Square::drawShape() {
	Color aux_color = getColor();
	Position aux_pos = getPosition();
	int x1 = aux_pos.position_x, y1 = aux_pos.position_y;
	int x2 = aux_pos.position_x + getSide(), y2 = aux_pos.position_y + getSide();
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

// --------------- TRIANGULO ---------------------------------
Triangle::Triangle() {
	setPosition(0, 0);
	setColor(1.0, 1.0, 1.0);
	setLineWidth(1);
	setBase(50);
	setHeight(25);
	setArea();
	setPerimeter();
}

Triangle::Triangle(int x, int y) {
	setPosition(x, y);
	setColor(1.0, 1.0, 1.0);
	setLineWidth(1);
	setBase(50);
	setHeight(25);
	setArea();
	setPerimeter();
}

Triangle::Triangle(int x, int y, int ba, int h) {
	setPosition(x, y);
	setColor(1.0, 1.0, 1.0);
	setLineWidth(1);
	setBase(ba);
	setHeight(h);
	setArea();
	setPerimeter();
}

Triangle::Triangle(int x, int y, int ba, int h, float r, float g, float b) {
	setPosition(x, y);
	setColor(r, g, b);
	setLineWidth(1);
	setBase(ba);
	setHeight(h);
	setArea();
	setPerimeter();
}

Triangle::Triangle(int x, int y, int ba, int h, float r, float g, float b, int lwidth) {
	setPosition(x, y);
	setColor(r, g, b);
	setLineWidth(lwidth);
	setBase(ba);
	setHeight(h);
	setArea();
	setPerimeter();
}

// ------- METODOS IMPLEMENTADOS DE LOS SETTERS --------------
void Triangle::setBase(int b) {
	if (b > 0) { base = b; }
	else { base = 50; }
}

void Triangle::setHeight(int h) {
	if (h > 0) { height = h; }
	else { height = 25; }
}

// ------- METODO PARA REALIZAR EL TRAZO DE LA FIGURA --------
void Triangle::drawShape() {
	Color aux_color = getColor();
	Position aux_pos = getPosition();
	int x1 = aux_pos.position_x, y1 = aux_pos.position_y;
	int x2 = aux_pos.position_x + (getBase() / 2), y2 = aux_pos.position_y + getHeight();
	int x3 = aux_pos.position_x + getBase(), y3 = y1;
	glColor3f(aux_color.colorR, aux_color.colorG, aux_color.colorB);
	glLineWidth(getLineWidth());
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x3, y3);
	glVertex2i(x1, y1);
	glEnd();
}
