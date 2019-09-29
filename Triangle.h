#pragma once
#include "Shapes.h"
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

