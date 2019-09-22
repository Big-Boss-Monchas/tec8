#ifndef SHAPES_H
#define SHAPES_H
#pragma once

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
		virtual void setPosition(int, int) = 0;
		virtual void setColor(float, float, float) = 0;
		virtual void setLineWidth(int) = 0;
		virtual void setArea(void) = 0;
		virtual void setPerimeter(void) = 0;

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
		double base;
		double height;

	// ----- PROTOTIPOS DE CONSTRUCTORES Y METODOS -----------
	public:
		Rectangle();
		Rectangle(int x, int y);
		Rectangle(int x, int y, int base, int height);
		Rectangle(int x, int y, int base, int height, float r, float g, float b);
		Rectangle(int x, int y, int base, int height, float r, float g, float b, int lwidth);

		void setPosition(int, int);
		void setColor(float, float, float);
		void setLineWidth(int);
		void setArea(void);
		void setPerimeter(void);
		void setBase(int);
		void setHeight(int);

		double getBase() const { return base; }
		double getHeight() const { return height; }

		double calculateArea() { return (base * height); }
		double calculatePerimeter() { return (2 * (base + height)); }
		void drawShape(void);
};

#endif // !SHAPES_H
