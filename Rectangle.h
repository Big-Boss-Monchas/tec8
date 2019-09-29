#pragma once

#include "Shapes.h"

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

	//Rectangle(const Rectangle& rectangle) {
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

	/*void drawShape(int NoVertex) {
		Color aux_color = getColor();
		Vertex aux_pos = getPosition();
		int x1 = aux_pos.getX(), y1 = aux_pos.getY();
		int x2 = aux_pos.getX() + getBase(), y2 = aux_pos.getY() + getHeight();
		int x[2], y[2];

		x[0] = aux_pos.getX(), y[0] = aux_pos.getY();
		x[1] = aux_pos.getX() + getBase(), y[1] = aux_pos.getY() + getHeight();

		setVertices(x, y);

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

	void calculateShape() {
		//Color aux_color = getColor();
		Vertex aux_pos = getPosition();
		int x1 = aux_pos.getX(), y1 = aux_pos.getY();
		int x2 = aux_pos.getX() + getBase(), y2 = aux_pos.getY() + getHeight();
		setVertices(x1, y1, x2, y2);
	}

	void drawShape() {
		Color aux_color = getColor();
		/*Vertex aux_pos = getPosition();
		int x1 = aux_pos.getX(), y1 = aux_pos.getY();
		int x2 = aux_pos.getX() + getBase(), y2 = aux_pos.getY() + getHeight();
		setVertices(x1, y1, x2, y2);*/
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
		
		/*//Linea 1
		glVertex2i(vertices[0].getX(), vertices[0].getY());
		glVertex2i(vertices[1].getX(), vertices[1].getY());
		//Linea 2
		glVertex2i(vertices[1].getX(), vertices[1].getY());
		glVertex2i(vertices[2].getX(), vertices[2].getY());
		//Linea 3
		glVertex2i(vertices[2].getX(), vertices[2].getY());
		glVertex2i(vertices[3].getX(), vertices[3].getY());
		//Linea 4
		glVertex2i(vertices[3].getX(), vertices[3].getY());
		glVertex2i(vertices[0].getX(), vertices[0].getY());*/

		glEnd();
	}
	void setVertices(int x1, int y1, int x2, int y2) {
		vertices[0].setX(x1), vertices[0].setY(y1); // vertice 1
		vertices[1].setX(x1), vertices[1].setY(y2); // vertice 2
		vertices[2].setX(x2), vertices[2].setY(y2); // vertice 3
		vertices[3].setX(x2), vertices[3].setY(y1); // vertice 4
	}
	void moveSquare(int _x, int _y) {
		/*vertices[0].moveVertex(_x, _y);
		vertices[1].moveVertex(_x, _y);
		vertices[2].moveVertex(_x, _y);
		vertices[3].moveVertex(_x, _y);*/
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

		/*vertices[0].moveVertex(-10, -10);
		vertices[1].moveVertex(-10, 10);
		vertices[2].moveVertex(10, 10);
		vertices[3].moveVertex(10, -10);*/
	}
};


