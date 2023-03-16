#include"draw.h"

void Draw::write(string str, GLfloat x, GLfloat y) {
	int len, i;
	glRasterPos2f(x, y);
	len = str.size();
	for (i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
}

void Draw::circle(GLfloat x, GLfloat y, GLfloat r) {
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	int n = 1000;
	for (int i = 0; i <= n; ++i) {
		double angle = i * 2 * PI / n;
		glVertex2f(x + r * cos(angle), y + r * sin(angle));
	}
	glEnd();
}

void Draw::line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}