#pragma once

#include "Shapes.h"
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
		//Color aux_color = getColor();
		Vertex aux_pos = getPosition();
		int x1 = aux_pos.getX(), y1 = aux_pos.getY();
		int x2 = aux_pos.getX() + getSide(), y2 = aux_pos.getY() + getSide();
		setVertices(x1, y1, x2, y2);
	}

	void drawShape() {
		Color aux_color = getColor();
		/*Color aux_color = getColor();
		Vertex aux_pos = getPosition();
		int x1 = aux_pos.getX(), y1 = aux_pos.getY();
		int x2 = aux_pos.getX() + getSide(), y2 = aux_pos.getY() + getSide();
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
		/*glVertex2i(x1, y1);	//vertice 1
		glVertex2i(x1, y2);	//vertice 2
		glVertex2i(x1, y2);
		glVertex2i(x2, y2);	//vertice 3
		glVertex2i(x2, y2);
		glVertex2i(x2, y1);	//vertice 4
		glVertex2i(x2, y1);
		glVertex2i(x1, y1);*/
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
		//position.moveVertex(_x, _y);

	}

	void scaleShape(float _x, float _y) {

		float sideScaledX = (vertices[3].getX()-vertices[0].getX()) * _x;
		float cambX = (sideScaledX - (vertices[3].getX() - vertices[0].getX()))/2;

		float sideScaledY = (vertices[1].getY() - vertices[0].getY()) * _y;
		float cambY = (sideScaledY - (vertices[1].getY() - vertices[0].getY())) / 2;

		vertices[0].moveVertex(-cambX, -cambY);
		vertices[1].moveVertex(-cambX, cambY);
		vertices[2].moveVertex(cambX, cambY);
		vertices[3].moveVertex(cambX, -cambY);

	}
};





