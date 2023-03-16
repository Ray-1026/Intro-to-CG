#pragma once
#include"draw.h"

class Player :public Draw {
private:
	float x = 0, y = -0.4;
public:
	int run = 0;
	void draw();
	void move(float);
	float show_x();
};

class Drop :public Draw {
private:
	float y = 0.9, x, speed;
public:
	int id;
	Drop(int, float, float);
	void draw();
	void move();
	float show_y();
	float show_x();
};