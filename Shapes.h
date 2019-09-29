#ifndef SHAPES_H
#define SHAPES_H
#pragma once
#include <cmath>
#include <GL/glut.h>

class Vertex {
private:
	float x;
	float y;
public:

	Vertex() {
		x = 0;
		y = 0;
	}

	Vertex(float _x, float _y) {
		x = _x;
		y = _y;
	}

	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	void setX(float _x) {
		x = _x;
	}
	void setY(float _y) {
		y = _y;
	}

	// Transformaciones

	void moveVertex(float _x, float _y) {
		x = x + _x;
		y = y + _y;
	}
	void scaleVertex(float _x, float _y) {
		x = x * _x;
		y = y * _y;
	}
};


// ------- CLASE PRINCIPAL ----------------------------------
class Shapes
{
	// ----- ATRIBUTOS DE LAS FIGURAS -----------------------
protected:
	Vertex position;
	int NoVertices;

	//Vertex vertices[];

	// CADA UNO CORRESPONDE A DIFERENTE COLOR
	// R = RED, G = GREEN, B = BLUE ---------------------
	struct Color
	{
		float colorR;
		float colorG;
		float colorB;
	};
	struct Color color;
	int lineWidth;
	double area;
	double perimeter;

	// ----- GETTERS & SETTERS -------------------------------
	// ALGUNAS SON VIRTUALES DEBIDO A QUE SERAN IMPLEMENTADAS
	// EN LA CLASE HIJA --------------------------------------
public:

	void setPosition(int _x, int _y) {
		position.setX(_x);
		position.setY(_y);
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
	void setNoVertices(int _NoVertices) {
		NoVertices = _NoVertices;
	}
	int getNoVertices() {
		return NoVertices;
	}

	Vertex getPosition() const { return position; }
	Color getColor() const { return color; }
	int getLineWidth() const { return lineWidth; }
	double getArea() const { return area; }
	double getPerimeter() const { return perimeter; }

	// --- METODOS DE LAS FIGURAS ------------------------
	virtual double calculateArea() = 0;
	virtual double calculatePerimeter() = 0;
	virtual void drawShape() = 0;
	

	void setVertices(Vertex vertices[], int _x[], int _y[]) {

		for (int i = 0, j = 0, k = 0; i < NoVertices; i++, k++) {
			if (k == NoVertices) {
				k = 0;
				j++;
			}
			vertices[i].setX(_x[j]);
			vertices[i].setY(_y[k]);
		}
	}

};
// ------- CLASE HIJA / RECTANGULO ---------------------------
class Rectangle : public Shapes {

	// ----- ATRIBUTOS PERTENECIENTES A RECTANGULO -----------
private:
	int base;
	int height;
	Vertex vertices[4];
	int NoVertices;

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
		setNoVertices(4);
		calculateShape();
	}

	Rectangle(int x, int y) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setBase(50);
		setHeight(25);
		setNoVertices(4);
		calculateShape();
	}

	Rectangle(int x, int y, int ba, int h) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setBase(ba);
		setHeight(h);
		setNoVertices(4);
		calculateShape();
	}

	Rectangle(int x, int y, int ba, int h, float r, float g, float b) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(1);
		setBase(ba);
		setHeight(h);
		setNoVertices(4);
		calculateShape();
	}

	Rectangle(int x, int y, int ba, int h, float r, float g, float b, int lwidth) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(lwidth);
		setBase(ba);
		setHeight(h);
		setNoVertices(4);
		calculateShape();
	}

	Rectangle(const Rectangle& rectangle) {
		Vertex pos = rectangle.getPosition();
		setPosition(pos.getX(), pos.getY());
		Color col = rectangle.getColor();
		setColor(col.colorR, col.colorG, col.colorB);
		setLineWidth(rectangle.getLineWidth());
		setBase(rectangle.getBase());
		setHeight(rectangle.getHeight());
		setNoVertices(4);
		calculateShape();
	};

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

	void calculateShape() {

		Vertex aux_pos = getPosition();
		int x1 = aux_pos.getX(), y1 = aux_pos.getY();
		int x2 = aux_pos.getX() + getBase(), y2 = aux_pos.getY() + getHeight();
		setVertices(x1, y1, x2, y2);
	}

	void drawShape() {
		Color aux_color = getColor();

		glColor3f(aux_color.colorR, aux_color.colorG, aux_color.colorB);
		glLineWidth(getLineWidth());
		glBegin(GL_LINES);

		for (int i = 0, j = 1, k = 0; i < 4; i++, j++, k++) {
			if (j == 4) {
				j = 0;
			}
			glVertex2i(vertices[k].getX(), vertices[k].getY());
			glVertex2i(vertices[j].getX(), vertices[j].getY());
		}

		glEnd();
	}
	void setVertices(int x1, int y1, int x2, int y2) {
		vertices[0].setX(x1), vertices[0].setY(y1); // vertice 1
		vertices[1].setX(x1), vertices[1].setY(y2); // vertice 2
		vertices[2].setX(x2), vertices[2].setY(y2); // vertice 3
		vertices[3].setX(x2), vertices[3].setY(y1); // vertice 4
	}
	void moveSquare(int _x, int _y) {
		position.moveVertex(_x, _y);
	}
	void scaleShape(float _x, float _y) {

		float sideScaledX = (vertices[3].getX() - vertices[0].getX()) * _x;
		float cambX = (sideScaledX - (vertices[3].getX() - vertices[0].getX())) / 2;

		float sideScaledY = (vertices[1].getY() - vertices[0].getY()) * _y;
		float cambY = (sideScaledY - (vertices[1].getY() - vertices[0].getY())) / 2;

		vertices[0].moveVertex(-cambX, -cambY);
		vertices[1].moveVertex(-cambX, cambY);
		vertices[2].moveVertex(cambX, cambY);
		vertices[3].moveVertex(cambX, -cambY);

	}
};

// ------- CLASE HIJA / CUADRADO -----------------------------
class Square : public Shapes {

	// ----- ATRIBUTOS PERTENECIENTES A CUADRADO -------------
private:
	int side;
	Vertex vertices[4];
	int NoVertices;

public:
	Square() {
		setPosition(0, 0);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setSide(50);
		setNoVertices(4);
		calculateShape();
	}

	Square(int x, int y) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setSide(50);
		setNoVertices(4);
		calculateShape();
	}

	Square(int x, int y, int s) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setSide(s);
		setNoVertices(4);
		calculateShape();
	}

	Square(int x, int y, int s, float r, float g, float b) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(1);
		setSide(s);
		setNoVertices(4);
		calculateShape();
	}

	Square(int x, int y, int s, float r, float g, float b, int lwidth) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(lwidth);
		setSide(s);
		setNoVertices(4);
		calculateShape();
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

	void calculateShape() {
		Vertex aux_pos = getPosition();
		int x1 = aux_pos.getX(), y1 = aux_pos.getY();
		int x2 = aux_pos.getX() + getSide(), y2 = aux_pos.getY() + getSide();
		setVertices(x1, y1, x2, y2);
	}

	void drawShape() {
		Color aux_color = getColor();

		glColor3f(aux_color.colorR, aux_color.colorG, aux_color.colorB);
		glLineWidth(getLineWidth());
		glBegin(GL_LINES);

		for (int i = 0, j = 1, k = 0; i < 4; i++, j++, k++) {
			if (j == 4) {
				j = 0;
			}
			glVertex2i(vertices[k].getX(), vertices[k].getY());
			glVertex2i(vertices[j].getX(), vertices[j].getY());
		}
		
		glEnd();
	}
	void setVertices(int x1, int y1, int x2, int y2) {
		vertices[0].setX(x1), vertices[0].setY(y1); // vertice 1
		vertices[1].setX(x1), vertices[1].setY(y2); // vertice 2
		vertices[2].setX(x2), vertices[2].setY(y2); // vertice 3
		vertices[3].setX(x2), vertices[3].setY(y1); // vertice 4
	}
	void setVertices(Vertex _vertices[]) {

	}

	void moveShape(int _x, int _y) {
		vertices[0].moveVertex(_x, _y);
		vertices[1].moveVertex(_x, _y);
		vertices[2].moveVertex(_x, _y);
		vertices[3].moveVertex(_x, _y);
	}

	void scaleShape(float _x, float _y) {

		float sideScaledX = (vertices[3].getX() - vertices[0].getX()) * _x;
		float cambX = (sideScaledX - (vertices[3].getX() - vertices[0].getX())) / 2;

		float sideScaledY = (vertices[1].getY() - vertices[0].getY()) * _y;
		float cambY = (sideScaledY - (vertices[1].getY() - vertices[0].getY())) / 2;

		vertices[0].moveVertex(-cambX, -cambY);
		vertices[1].moveVertex(-cambX, cambY);
		vertices[2].moveVertex(cambX, cambY);
		vertices[3].moveVertex(cambX, -cambY);

	}
};
// ------- CLASE HIJA / TRIANGULO ----------------------------
class Triangle : public Shapes {

	// ----- ATRIBUTOS PERTENECIENTES A TRIANGULO ------------
private:
	int base;
	int height;
	Vertex vertices[3];

public:
	Triangle() {
		setPosition(0, 0);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setBase(50);
		setHeight(25);
		setNoVertices(3);

	}

	Triangle(int x, int y) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setBase(50);
		setHeight(25);
		area = calculateArea();
		perimeter = calculatePerimeter();
		setNoVertices(3);
	}

	Triangle(int x, int y, int ba, int h) {
		setPosition(x, y);
		setColor(1.0, 1.0, 1.0);
		setLineWidth(1);
		setBase(ba);
		setHeight(h);
		area = calculateArea();
		perimeter = calculatePerimeter();
		setNoVertices(3);
	}

	Triangle(int x, int y, int ba, int h, float r, float g, float b) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(1);
		setBase(ba);
		setHeight(h);
		area = calculateArea();
		perimeter = calculatePerimeter();
		setNoVertices(3);
	}

	Triangle(int x, int y, int ba, int h, float r, float g, float b, int lwidth) {
		setPosition(x, y);
		setColor(r, g, b);
		setLineWidth(lwidth);
		setBase(ba);
		setHeight(h);
		area = calculateArea();
		perimeter = calculatePerimeter();
		setNoVertices(3);
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
		Vertex aux_pos = getPosition();

		int x[3], y[3];
		x[0] = aux_pos.getX(), y[0] = aux_pos.getY();
		x[1] = aux_pos.getX() + (getBase() / 2), y[1] = aux_pos.getY() + getHeight();
		x[2] = aux_pos.getX() + getBase(), y[2] = y[0];

		setVertices(vertices, x, y);

		glColor3f(aux_color.colorR, aux_color.colorG, aux_color.colorB);
		glLineWidth(getLineWidth());
		glBegin(GL_LINES);
		for (int i = 0, j = 1; i < 3; i++, j++) {
			if (j == 3) {
				j = 0;
			}
			glVertex2i(x[i], y[i]);
			glVertex2i(x[j], y[j]);
		}
		glEnd();
	}
	void scaleShape(int _x, int _y) {
		vertices[0].scaleVertex(_x, _y);
		vertices[1].scaleVertex(_x, _y);
		vertices[2].scaleVertex(_x, _y);
		vertices[3].scaleVertex(_x, _y);
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
		Vertex aux_pos;
		aux_pos.setX(0);
		aux_pos.setY(getRadius());
		glColor3f(aux_color.colorR, aux_color.colorG, aux_color.colorB);
		glPointSize(getLineWidth());
		float midpoint = 1 - radius;
		circlePlotPoints(position.getX(), position.getY(), aux_pos);
		while (aux_pos.getX() < aux_pos.getY())
		{
			aux_pos.setX(aux_pos.getX() + 1);
			if (midpoint < 0)
			{
				midpoint += 2 * aux_pos.getX() + 1;
			}
			else
			{
				aux_pos.setY(aux_pos.getY() - 1);
				midpoint += 2 * (aux_pos.getX() - aux_pos.getY()) + 1;
			}
			circlePlotPoints(position.getX(), position.getY(), aux_pos);
		}
	}

	void circlePlotPoints(int x, int y, Vertex aux_pos) {
		glBegin(GL_POINTS);
		glVertex2i(x + aux_pos.getX(), y + aux_pos.getY());
		glVertex2i(x - aux_pos.getX(), y + aux_pos.getY());
		glVertex2i(x + aux_pos.getX(), y - aux_pos.getY());
		glVertex2i(x - aux_pos.getX(), y - aux_pos.getY());

		glVertex2i(x + aux_pos.getY(), y + aux_pos.getX());
		glVertex2i(x - aux_pos.getY(), y + aux_pos.getX());
		glVertex2i(x + aux_pos.getY(), y - aux_pos.getX());
		glVertex2i(x - aux_pos.getY(), y - aux_pos.getX());

		glEnd();
	}

	void drawShapeTrig() {
		Color aux_color = getColor();
		Vertex aux_pos = getPosition();
		glColor3f(aux_color.colorR, aux_color.colorG, aux_color.colorB);
		glLineWidth(getLineWidth());
		int circle_points = 100;
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < circle_points; i++)
		{
			float angle = 2 * PI * float(i) / circle_points;
			glVertex2f(aux_pos.getX() + getRadius() * cos(angle), aux_pos.getY() + getRadius() * sin(angle));
		}
		glEnd();
	}
	void scaleShape(int _x, int _y) {
		
	}
};
#endif // !SHAPES_H