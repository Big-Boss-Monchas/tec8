#pragma once

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

