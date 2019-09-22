#ifndef SHAPES_H
#define SHAPES_H
#pragma once
#include <cmath>
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
		void setArea(void) { area = calculateArea(); }
		void setPerimeter(void) { perimeter = calculatePerimeter(); }

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

	// ----- PROTOTIPOS DE CONSTRUCTORES Y METODOS -----------
	public:
		Rectangle();
		Rectangle(int x, int y);
		Rectangle(int x, int y, int base, int height);
		Rectangle(int x, int y, int base, int height, float r, float g, float b);
		Rectangle(int x, int y, int base, int height, float r, float g, float b, int lwidth);

		void setBase(int);
		void setHeight(int);

		int getBase() const { return base; }
		int getHeight() const { return height; }

		double calculateArea() { return (base * height); }
		double calculatePerimeter() { return (2 * (base + height)); }
		void drawShape(void);
};

// ------- CLASE HIJA / CUADRADO -----------------------------
class Square : public Shapes {

	// ----- ATRIBUTOS PERTENECIENTES A CUADRADO -------------
	private:
		int side;

	public:
		Square();
		Square(int x, int y);
		Square(int x, int y, int s);
		Square(int x, int y, int s, float r, float g, float b);
		Square(int x, int y, int s, float r, float g, float b, int lwidth);

		void setSide(int);

		int getSide() const { return side; }

		double calculateArea() { return (side * side); }
		double calculatePerimeter() { return (4 * side); }
		void drawShape(void);
};

// ------- CLASE HIJA / TRIANGULO ----------------------------
class Triangle : public Shapes {

	// ----- ATRIBUTOS PERTENECIENTES A TRIANGULO ------------
	private:
		int base;
		int height;

	public:
		Triangle();
		Triangle(int x, int y);
		Triangle(int x, int y, int base, int height);
		Triangle(int x, int y, int base, int height, float r, float g, float b);
		Triangle(int x, int y, int base, int height, float r, float g, float b, int lwidth);

		void setBase(int);
		void setHeight(int);

		int getBase() const { return base; }
		int getHeight() const { return height; }

		double calculateArea() { return (base * height) / 2; }
		double calculatePerimeter() { 
			double side_a = sqrt(pow(base, 2) + pow(height, 2));
			return ((2 * side_a) * base); 
		}
		void drawShape(void);
};

#endif // !SHAPES_H
