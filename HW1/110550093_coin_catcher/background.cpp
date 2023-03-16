#include"background.h"

Background::Background() {
	ifstream input("record.txt");
	input >> highest_score;
	input.close();
	count = 0;
}

void Background::start() {
	count++;

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glPopMatrix();

	glLineWidth(2.5);
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.8, 0.8);
	glVertex2f(0.8, 0.8);
	glVertex2f(0.8, -0.8);
	glVertex2f(-0.8, -0.8);
	glEnd();

	glColor3f(0.8, 0, 0);
	if (flag) {
		glLineWidth(2.5);
		glBegin(GL_LINE_LOOP);
	}
	else
		glBegin(GL_QUADS);
	glVertex2f(-0.25, -0.4);
	glVertex2f(-0.25, -0.6);
	glVertex2f(0.25, -0.6);
	glVertex2f(0.25, -0.4);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.45, 0.15);
	glVertex2f(-0.45, -0.05);
	glVertex2f(-0.35, -0.05);
	glVertex2f(-0.35, 0.15);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.275, 0.15);
	glVertex2f(-0.275, -0.05);
	glVertex2f(-0.175, -0.05);
	glVertex2f(-0.175, 0.15);
	glEnd();

	line(-0.38, 0.05, -0.42, 0.05);
	line(-0.42, 0.05, -0.395, 0.09);
	line(-0.42, 0.05, -0.395, 0.01);
	line(-0.205, 0.05, -0.245, 0.05);
	line(-0.205, 0.05, -0.23, 0.09);
	line(-0.205, 0.05, -0.23, 0.01);

	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 0.15);
	glVertex2f(0.5, 0.15);
	glVertex2f(0.5, -0.05);
	glVertex2f(0, -0.05);
	glEnd();

	write("Move :", -0.35, 0.27);
	write("Pause :", 0.21, 0.27);
	write("Space", 0.22, 0.04);
	write("Click Here to Play", -0.13, -0.52);

	glColor3f(1, 0, 0);
	write("- - - - - Welcome to the COIN CATCHER GAME - - - - -", -0.45, 0.6);
}

void Background::loading() {
	count++;
	flag = 1;

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.6, 0.6, 0.6, 0);
	glColor3f(0, 0, 0);
	write("Loading...", -0.1, 0.3);

	glColor3f(1, 1, 1);
	glLineWidth(4);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5, 0.15);
	glVertex2f(0.5, 0.15);
	glVertex2f(0.5, -0.05);
	glVertex2f(-0.5, -0.05);
	glEnd();

	glBegin(GL_QUADS);
	if (loading_time > 0) {
		glVertex2f(-0.48, 0.13);
		glVertex2f(-0.38, 0.13);
		glVertex2f(-0.42, -0.03);
		glVertex2f(-0.48, -0.03);
	}
	if (loading_time > 1) {
		glVertex2f(-0.35, 0.13);
		glVertex2f(-0.25, 0.13);
		glVertex2f(-0.29, -0.03);
		glVertex2f(-0.39, -0.03);
	}
	if (loading_time > 2) {
		glVertex2f(-0.22, 0.13);
		glVertex2f(-0.12, 0.13);
		glVertex2f(-0.16, -0.03);
		glVertex2f(-0.26, -0.03);
	}
	if (loading_time > 3) {
		glVertex2f(-0.09, 0.13);
		glVertex2f(0.01, 0.13);
		glVertex2f(-0.03, -0.03);
		glVertex2f(-0.13, -0.03);
	}
	if (loading_time > 4) {
		glVertex2f(0.04, 0.13);
		glVertex2f(0.14, 0.13);
		glVertex2f(0.1, -0.03);
		glVertex2f(0, -0.03);
	}
	if (loading_time > 5) {
		glVertex2f(0.17, 0.13);
		glVertex2f(0.27, 0.13);
		glVertex2f(0.23, -0.03);
		glVertex2f(0.13, -0.03);
	}
	if (loading_time > 6) {
		glVertex2f(0.3, 0.13);
		glVertex2f(0.4, 0.13);
		glVertex2f(0.36, -0.03);
		glVertex2f(0.26, -0.03);
	}
	if (loading_time > 7) {
		glVertex2f(0.43, 0.13);
		glVertex2f(0.47, 0.13);
		glVertex2f(0.47, -0.03);
		glVertex2f(0.39, -0.03);
	}
	glEnd();

	glColor3f(0.95, 0.8, 0.05);
	circle(-0.59, -0.3, 0.05);
	glColor3f(1, 1, 0);
	circle(-0.6, -0.3, 0.05);
	glColor3f(0.95, 0.9, 0);
	circle(-0.6, -0.3, 0.04);
	glColor3f(0.5, 0.35, 0.05);
	write("$", -0.608, -0.32);
	glColor3f(0, 0, 0);
	write("+15", -0.5, -0.32);

	glColor3f(0.345, 0.345, 0.345);
	circle(0.51, -0.3, 0.05);
	glColor3f(0.75, 0.75, 0.75);
	circle(0.5, -0.3, 0.05);
	glColor3f(0, 0, 0);
	circle(0.5, -0.3, 0.04);
	glColor3f(1, 1, 1);
	write("X", 0.488, -0.32);
	glColor3f(0, 0, 0);
	write("GAMEOVER", 0.6, -0.32);

	glColor3f(0.69, 0.09, 0.12);
	circle(-0.04, -0.3, 0.05);
	glColor3f(1, 0, 0);
	circle(-0.05, -0.3, 0.05);
	glColor3f(0.89, 0.09, 0.05);
	circle(-0.05, -0.3, 0.04);
	glColor3f(1, 1, 1);
	write("x", -0.06, -0.315);
	glColor3f(0, 0, 0);
	write("-10", 0.05, -0.32);

	loading_time += 0.025;
	if (loading_time >= 8) {
		menu = 2;
		loading_time = 1;
	}
}

void Background::game_background(GLint width, GLint height, GLubyte* pixeldata) {
	string times = "0" + to_string(time / 60) + " : ";
	if (time % 60 < 10)
		times += "0";
	times += to_string(time % 60);

	glClear(GL_COLOR_BUFFER_BIT);
	glPixelZoom(3.6, 3);
	glRasterPos2f(-1, -1);
	glDrawPixels(width, height, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixeldata);

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.87, 0.96);
	glVertex2f(0.97, 0.96);
	glVertex2f(0.97, 0.84);
	glVertex2f(0.87, 0.84);
	glEnd();

	if (gamestatus) {
		glLineWidth(6);
		glBegin(GL_LINES);
		line(0.9, 0.94, 0.9, 0.86);
		line(0.94, 0.94, 0.94, 0.86);
		glEnd();
	}
	else {
		glBegin(GL_TRIANGLES);
		glVertex2f(0.89, 0.94);
		glVertex2f(0.89, 0.86);
		glVertex2f(0.95, 0.9);
		glEnd();
	}

	highest_score = (highest_score > score) ? (highest_score) : (score);

	write("   Player Score : " + to_string(score), -0.9, 0.82);
	write("Highest Score : " + to_string(highest_score), -0.9, 0.72);
	write("               Time : ", -0.9, 0.62);
	if (time < 11)
		glColor3f(1, 0, 0);
	else
		glColor3f(0, 1, 1);
	write(times, -0.67, 0.62);

	if (!time || gamestatus == 2) {
		gamestatus = 2;
		glColor3f(1, 0, 0);
		glBegin(GL_QUADS);
		glVertex2f(-1, 0.06);
		glVertex2f(-1, -0.06);
		glVertex2f(1, -0.06);
		glVertex2f(1, 0.06);
		glEnd();

		glColor3f(1, 1, 1);
		write("GAME OVER !!!", -0.15, -0.025);

		loading_time += 0.025;
		if (loading_time >= 8) {
			menu = 3;
			count = 0;
			loading_time = 1;
		}
	}
}

void Background::over() {
	count++;

	ofstream output("record.txt", ios::trunc);
	output << highest_score;
	output.close();

	time = 90;
	gamestatus = 1;

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glPopMatrix();

	glLineWidth(2.5);
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.8, 0.8);
	glVertex2f(0.8, 0.8);
	glVertex2f(0.8, -0.8);
	glVertex2f(-0.8, -0.8);
	glEnd();

	glColor3f(1, 0, 0);
	if (flag == 0)
		glBegin(GL_QUADS);
	else
		glBegin(GL_LINE_LOOP);
	glVertex2f(-0.6, -0.4);
	glVertex2f(-0.1, -0.4);
	glVertex2f(-0.1, -0.6);
	glVertex2f(-0.6, -0.6);
	glEnd();

	if (flag == 2)
		glBegin(GL_QUADS);
	else
		glBegin(GL_LINE_LOOP);
	glVertex2f(0.1, -0.4);
	glVertex2f(0.6, -0.4);
	glVertex2f(0.6, -0.6);
	glVertex2f(0.1, -0.6);
	glEnd();

	glColor3f(1, 1, 1);
	write("Exit", -0.385, -0.52);
	write("Restart", 0.3, -0.52);
	write("              Score : ", -0.4, 0.3);
	write("Highest Score : ", -0.4, 0);
	write(to_string(score), 0., 0.3);
	write(to_string(highest_score), 0, 0);

	glColor3f(1, 0, 0);
	write("- - - - - COIN CATCHER GAME - - - - -", -0.33, 0.6);
}

void Background::changeStatus() {
	gamestatus = (gamestatus != 2) ? ((gamestatus) ? (0) : (1)) : (2);
}