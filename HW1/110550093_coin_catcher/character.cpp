#include"character.h"

void Player::draw() {
	glColor3f(0, 0, 0);
	circle(x, y, 0.04);
	glLineWidth(4);
	switch (run) {
	case 0:
		line(x, y, x, y - 0.18);
		line(x, y - 0.07, x - 0.05, y - 0.13);
		line(x, y - 0.07, x + 0.05, y - 0.13);
		line(x, y - 0.18, x - 0.05, y - 0.24);
		line(x, y - 0.18, x + 0.05, y - 0.24);
		break;
	case 1:
		line(x, y, x + 0.04, y - 0.13);
		line(x + 0.025, y - 0.07, x - 0.025, y - 0.1);
		line(x - 0.025, y - 0.1, x - 0.05, y - 0.04);
		line(x + 0.025, y - 0.07, x + 0.06, y - 0.03);
		line(x + 0.06, y - 0.03, x + 0.1, y - 0.08);
		line(x + 0.04, y - 0.13, x , y - 0.17);
		line(x, y - 0.17, x-0.01, y - 0.24);
		line(x + 0.04, y - 0.13, x+0.07, y - 0.21);
		line(x + 0.07, y - 0.21, x+0.11, y - 0.17);
		break;
	case 2:
		line(x, y, x - 0.04, y - 0.13);
		line(x - 0.025, y - 0.07, x + 0.025, y - 0.1);
		line(x + 0.025, y - 0.1, x + 0.05, y - 0.04);
		line(x - 0.025, y - 0.07, x - 0.06, y - 0.03);
		line(x - 0.06, y - 0.03, x - 0.1, y - 0.08);
		line(x - 0.04, y - 0.13, x, y - 0.17);
		line(x, y - 0.17, x + 0.01, y - 0.24);
		line(x - 0.04, y - 0.13, x - 0.07, y - 0.21);
		line(x - 0.07, y - 0.21, x - 0.11, y - 0.17);
		break;
	}
}

float Player::show_x() {
	return x;
}

void Player::move(float new_x) {
	x += new_x;
}

Drop::Drop(int id, float x, float speed) {
	this->id = id;
	this->x = x;
	this->speed = speed;
}

void Drop::draw() {
	switch(id) {
	case 1:
		glColor3f(0.95, 0.8, 0.05);
		circle(x + 0.01, y, 0.05);
		glColor3f(1, 1, 0);
		circle(x, y, 0.05);
		glColor3f(0.95, 0.9, 0);
		circle(x, y, 0.04);
		glColor3f(0.5, 0.35, 0.05);
		write("$", x - 0.008, y - 0.02);
		break;
	case 0:
		glColor3f(0.345, 0.345, 0.345);
		circle(x + 0.01, y, 0.05);
		glColor3f(0.75, 0.75, 0.75);
		circle(x, y, 0.05);
		glColor3f(0, 0, 0);
		circle(x, y, 0.04);
		glColor3f(1, 1, 1);
		write("X", x - 0.012, y - 0.02);
		break;
	case 2:
		glColor3f(0.69, 0.09, 0.12);
		circle(x + 0.01, y, 0.05);
		glColor3f(1, 0, 0);
		circle(x, y, 0.05);
		glColor3f(0.89, 0.09, 0.05);
		circle(x, y, 0.04);
		glColor3f(1, 1, 1);
		write("x", x - 0.01, y - 0.015);
		break;
	}
}

void Drop::move() {
	y -= speed;
}

float Drop::show_y() {
	return y;
}

float Drop::show_x() {
	return x;
}