#ifndef SHAPES_H
#define SHAPES_H
#pragma once
#include <cmath>
#include <GL/glut.h>
#include "Vertex.h"



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
	/*virtual int getBase() = 0;
	virtual int getHeight() = 0;*/
	//virtual void setVertices() = 0;

	/*void drawShape(Vertex vertices[], int x[], int y[], int NoVertex, Color _color) {
		
		//Color aux_color = getColor();
		
		/*int x1 = aux_pos.getX(), y1 = aux_pos.getY();
		int x2 = aux_pos.getX() + getBase(), y2 = aux_pos.getY() + getHeight();*/

		/*int x[2], y[2];

		x[0] = aux_pos.getX(), y[0] = aux_pos.getY();
		x[1] = aux_pos.getX() + getBase(), y[1] = aux_pos.getY() + getHeight();
		
		//setVertices(vertices, x, y);

		Color aux_color = _color;
		Vertex aux_pos = getPosition();
		glColor3f(aux_color.colorR, aux_color.colorG, aux_color.colorB);
		glLineWidth(getLineWidth());
		glBegin(GL_LINES);

		for (int i = 0, j = 0; i < NoVertex; i++, j++) {
			if (i == NoVertex - 1) {
				j = 0;
			}
			glVertex2i(vertices[i].getX(), vertices[i].getY());
			glVertex2i(vertices[j].getX(), vertices[j].getY());
		}

		glEnd();
	}*/

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
	/*void moveShape(int _x, int _y) {
		/*vertices[0].moveVertex(_x, _y);
		vertices[1].moveVertex(_x, _y);
		vertices[2].moveVertex(_x, _y);
		vertices[3].moveVertex(_x, _y);
		//position.moveVertex(_x, _y);
		
	}*/
	//virtual void scaleShape(int _x, int _y) = 0;
};
#endif // !SHAPES_H