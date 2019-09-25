#ifndef SHAPES_H
#define SHAPES_H
#pragma once
#include <cmath>
#include <GL/glut.h>

// ------- CLASE PRINCIPAL ----------------------------------
class Shapes
{
	// ----- ATRIBUTOS DE LAS FIGURAS -----------------------
protected:
	struct Position
	{
		int position_x;
		int position_y;
	};

	// CADA UNO CORRESPONDE A DIFERENTE COLOR
	// R = RED, G = GREEN, B = BLUE ---------------------
	struct Color
	{
		float colorR;
		float colorG;
		float colorB;
	};
	struct Position point;
	struct Color color;
	int lineWidth;
	double area;
	double perimeter;

	// ----- GETTERS & SETTERS -------------------------------
	// ALGUNAS SON VIRTUALES DEBIDO A QUE SERAN IMPLEMENTADAS
	// EN LA CLASE HIJA --------------------------------------
public:
	void setPosition(int x, int y) {
		point.position_x = x;
		point.position_y = y;
	}
	void setColor(float r, float g, float b) {
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
	void setLineWidth(int width) {
		if (width > 0) lineWidth = width;
		else lineWidth = 1;
	}

	Position getPosition() const { return point; }
	Color getColor() const { return color; }
	int getLineWidth() const { return lineWidth; }
	double getArea() const { return area; }
	double getPerimeter() const { return perimeter; }

	// --- METODOS DE LAS FIGURAS ------------------------
	virtual double calculateArea() = 0;
	virtual double calculatePerimeter() = 0;
	virtual void drawShape() = 0;
};

// ------- CLASE HIJA / RECTANGULO ---------------------------
class Rectangle : public Shapes {

	// ----- ATRIBUTOS PERTENECIENTES A RECTANGULO -----------
private:
	int base;
	int height;

public:
	// ------- CONSTRUCTORES SOBRECARGADOS -----------------------
	// DE CREARSE EL OBJETO VACIO, AUTOMATICAMENTE SON ASIGNADOS
	// LOS VALORES FALTANTES, DEL MISMO MODO CON LOS OTROS 
	// CONSTRUCTORES QUE NO SE ENVIAN LOS PARAMETROS COMPLETOS ---
	Rectangle() {
		setPosition(0, 0);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setBase(50);
		setHeight(25);
	}

	Rectangle(int x, int y) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setBase(50);
		setHeight(25);
	}

	Rectangle(int x, int y, int ba, int h) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setBase(ba);
		setHeight(h);
	}

	Rectangle(int x, int y, int ba, int h, float r, float g, float b) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(1);
		setBase(ba);
		setHeight(h);
	}

	Rectangle(int x, int y, int ba, int h, float r, float g, float b, int lwidth) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(lwidth);
		setBase(ba);
		setHeight(h);
	}

	// ------- METODOS IMPLEMENTADOS DE LOS SETTERS --------------
	// SI ALGUNOS VALORES IMPORTANTES QUE PUDIESEN AFECTAR EL
	// FUNCIONAMIENTO DEL SET NO CONOCEN LOS REQUISITOS
	// NECESARIOS, SON ASIGNADOS VALORES PREDEFINIDOS ------------
	void setBase(int b) {
		if (b > 0) { base = b; }
		else { base = 50; }
		area = calculateArea();
		perimeter = calculatePerimeter();
	}

	void setHeight(int h) {
		if (h > 0) { height = h; }
		else { height = 25; }
		area = calculateArea();
		perimeter = calculatePerimeter();
	}

	int getBase() const { return base; }
	int getHeight() const { return height; }

	double calculateArea() { return (base * height); }
	double calculatePerimeter() { return (2 * (base + height)); }

	void drawShape() {
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
};

// ------- CLASE HIJA / CUADRADO -----------------------------
class Square : public Shapes {

	// ----- ATRIBUTOS PERTENECIENTES A CUADRADO -------------
private:
	int side;

public:
	Square() {
		setPosition(0, 0);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setSide(50);
	}

	Square(int x, int y) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setSide(50);
	}

	Square(int x, int y, int s) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setSide(s);
	}

	Square(int x, int y, int s, float r, float g, float b) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(1);
		setSide(s);
	}

	Square(int x, int y, int s, float r, float g, float b, int lwidth) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(lwidth);
		setSide(s);
	}

	void setSide(int s) {
		if (s > 0) { side = s; }
		else { side = 50; }
		area = calculateArea();
		perimeter = calculatePerimeter();
	}

	int getSide() const { return side; }

	double calculateArea() { return (side * side); }
	double calculatePerimeter() { return (4 * side); }

	void drawShape() {
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
};

// ------- CLASE HIJA / TRIANGULO ----------------------------
class Triangle : public Shapes {

	// ----- ATRIBUTOS PERTENECIENTES A TRIANGULO ------------
private:
	int base;
	int height;

public:
	Triangle() {
		setPosition(0, 0);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setBase(50);
		setHeight(25);
	}

	Triangle(int x, int y) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setBase(50);
		setHeight(25);
	}

	Triangle(int x, int y, int ba, int h) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setBase(ba);
		setHeight(h);
	}

	Triangle(int x, int y, int ba, int h, float r, float g, float b) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(1);
		setBase(ba);
		setHeight(h);
	}

	Triangle(int x, int y, int ba, int h, float r, float g, float b, int lwidth) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(lwidth);
		setBase(ba);
		setHeight(h);
	}

	void setBase(int b) {
		if (b > 0) { base = b; }
		else { base = 50; }
		area = calculateArea();
		perimeter = calculatePerimeter();
	}

	void setHeight(int h) {
		if (h > 0) { height = h; }
		else { height = 25; }
		area = calculateArea();
		perimeter = calculatePerimeter();
	}

	int getBase() const { return base; }
	int getHeight() const { return height; }

	double calculateArea() { return (base * height) / 2; }

	double calculatePerimeter() {
		double side_a = sqrt(pow(base, 2) + pow(height, 2));
		return ((2 * side_a) * base);
	}

	void drawShape() {
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
};

class Circle : public Shapes {
private:
	int radius;
	int diameter;
	const double PI = 3.141592;

public:
	Circle() {
		setPosition(0, 0);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setRadius(25);

	}

	Circle(int x, int y) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setRadius(25);
	}

	Circle(int x, int y, int rad) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setRadius(rad);
	}

	Circle(int x, int y, int rad, float r, float g, float b) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(1);
		setRadius(rad);
	}

	Circle(int x, int y, int rad, float r, float g, float b, int lwidth) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(lwidth);
		setRadius(rad);
	}

	void setRadius(int rad) {
		if (rad > 0) { radius = rad; }
		else { radius = 50; }
		diameter = getRadius() * 2;
		area = calculateArea();
		perimeter = calculatePerimeter();
	}

	int getRadius() const { return radius; }
	int getDiameter() const { return diameter; }

	double calculateArea() { return (PI * (pow(radius, 2))); }
	double calculatePerimeter() { return (2 * PI * radius); }

	void drawShape() {
		Color aux_color = getColor();
		Position aux_pos;
		aux_pos.position_x = 0;
		aux_pos.position_y = getRadius();
		glColor3f(aux_color.colorR, aux_color.colorG, aux_color.colorB);
		glPointSize(getLineWidth());
		float midpoint = 1 - radius;
		circlePlotPoints(point.position_x, point.position_y, aux_pos);
		while (aux_pos.position_x < aux_pos.position_y)
		{
			aux_pos.position_x++;
			if (midpoint < 0)
			{
				midpoint += 2 * aux_pos.position_x + 1;
			}
			else
			{
				aux_pos.position_y--;
				midpoint += 2 * (aux_pos.position_x - aux_pos.position_y) + 1;
			}
			circlePlotPoints(point.position_x, point.position_y, aux_pos);
		}
	}

	void circlePlotPoints(int x, int y, Position aux_pos) {
		glBegin(GL_POINTS);
		glVertex2i(x + aux_pos.position_x, y + aux_pos.position_y);
		glVertex2i(x - aux_pos.position_x, y + aux_pos.position_y);
		glVertex2i(x + aux_pos.position_x, y - aux_pos.position_y);
		glVertex2i(x - aux_pos.position_x, y - aux_pos.position_y);
		glVertex2i(x + aux_pos.position_y, y + aux_pos.position_x);
		glVertex2i(x - aux_pos.position_y, y + aux_pos.position_x);
		glVertex2i(x + aux_pos.position_y, y - aux_pos.position_x);
		glVertex2i(x - aux_pos.position_y, y - aux_pos.position_x);
		glEnd();
	}

	void drawShapeTrig() {
		Color aux_color = getColor();
		Position aux_pos = point;
		glColor3f(aux_color.colorR, aux_color.colorG, aux_color.colorB);
		glLineWidth(getLineWidth());
		int circle_points = 100;
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < circle_points; i++)
		{
			float angle = 2 * PI * float(i) / circle_points;
			glVertex2f(aux_pos.position_x + getRadius() * cos(angle), aux_pos.position_y + getRadius() * sin(angle));
		}
		glEnd();
	}
};

#endif // !SHAPES_H
