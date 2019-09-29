#pragma once

#include "Shapes.h"

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
				//int newY = aux_pos.getY() - 1;
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
		/*vertices[0].scaleVertex(_x, _y);
		vertices[1].scaleVertex(_x, _y);
		vertices[2].scaleVertex(_x, _y);
		vertices[3].scaleVertex(_x, _y);*/
	}
};

