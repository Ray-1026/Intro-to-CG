#define _CRT_SECURE_NO_WARNINGS
#include"background.h"
#include"character.h"
#include<queue>
#define path "..\\image\\background.bmp"
using namespace std;

static GLint imagewidth;
static GLint imageheight;
static GLint pixellength;
static GLubyte* pixeldata;

int cnt = 0;
Player p;
Background bg;
vector<Drop> coin;
queue<float> x, speed;

void passive(int x, int y) {
	if (bg.menu == 0) {
		if (525 < x && x < 874 && 590 < y && y < 674)
			bg.flag = 0;
		else
			bg.flag = 1;
	}
	else if (bg.menu == 3) {
		if (278 < x && x < 628 && 569 < y && y < 694)
			bg.flag = 0;
		else if (770 < x && x < 1120 && 569 < y && y < 694)
			bg.flag = 2;
		else
			bg.flag = 1;
	}
}

void OnMouse(int button, int state, int x, int y) {
	switch (bg.menu) {
	case 0:
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (525 < x && x < 874 && 590 < y && y < 674) {
				bg.menu = 1;
				bg.count = 0;
			}
		}
		break;
	case 3:
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (278 < x && x < 628 && 569 < y && y < 694)
				exit(0);
			else if (770 < x && x < 1120 && 569 < y && y < 694) {
				bg.score = 0;
				bg.menu = 1;
				bg.count = 0;
			}
		}
		break;
	}
}

void key(int key, int x, int y) {
	if (bg.menu == 2 && bg.gamestatus == 1) {
		if (key == GLUT_KEY_RIGHT && p.show_x() < 0.95) {
			p.move(0.06);
			p.run = 2;
		}
		else if (key == GLUT_KEY_LEFT && p.show_x() > (-0.95)) {
			p.move(-0.06);
			p.run = 1;
		}
		glutPostRedisplay();
	}
}

void key_up(int key, int x, int y) {
	p.run = 0;
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 32 && bg.menu == 2)
		bg.changeStatus();
}

void timer(int value) {
	glutTimerFunc(1000, timer, 0);
	bg.time -= (bg.menu == 2 && bg.gamestatus == 1) ? (1) : (0);
}

void display(void) {
	switch (bg.menu) {
	case 0:
		if (!bg.count)
			PlaySound(TEXT("..\\audio\\bg.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		bg.start();
		break;
	case 1:
		if(!bg.count)
			PlaySound(TEXT("..\\audio\\empty.wav"), NULL, SND_FILENAME | SND_ASYNC);
		bg.loading();
		break;
	case 2:
		bg.game_background(imagewidth, imageheight, pixeldata);
		p.draw();
		if (bg.gamestatus != 2) {
			for (int i = 0; i < coin.size(); ++i) {
				if (coin[i].show_y() < -0.37)
					coin.erase(coin.begin() + i);
				else if (coin[i].show_y() < -0.31 && -0.08 < coin[i].show_x() - p.show_x() && coin[i].show_x() - p.show_x() < 0.08) {
					if (coin[i].id == 1) {
						bg.score += 15;
						PlaySound(TEXT("..\\audio\\coin.wav"), NULL, SND_FILENAME | SND_ASYNC);
					}
					else if (coin[i].id == 0) {
						bg.gamestatus = 2;
						PlaySound(TEXT("..\\audio\\gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
					}
					else {
						bg.score -= 10;
						PlaySound(TEXT("..\\audio\\scream.wav"), NULL, SND_FILENAME | SND_ASYNC);
					}
					coin.erase(coin.begin() + i);
				}
				else {
					coin[i].draw();
					if (bg.gamestatus == 1)
						coin[i].move();
				}
			}
			if (coin.size() < 5) {
				cnt++;
				if (cnt == 12) {
					cnt = 0;
					coin.push_back(Drop(0, x.front(), speed.front()));
				}
				else if (cnt % 3 == 0)
					coin.push_back(Drop(2, x.front(), speed.front()));
				else
					coin.push_back(Drop(1, x.front(), speed.front()));
				x.push(x.front());
				speed.push(speed.front());
				x.pop();
				speed.pop();
			}
		}
		break;
	case 3:
		if(!bg.count)
			PlaySound(TEXT("..\\audio\\bg.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		bg.over();
		break;
	}
	glutSwapBuffers();
}

void idle(void) {
	display();
}

int main(int argc, char* argv[]) {
	FILE* pfile = fopen(path, "rb");
	fseek(pfile, 0x0012, SEEK_SET);
	fread(&imagewidth, sizeof(imagewidth), 1, pfile);
	fread(&imageheight, sizeof(imageheight), 1, pfile);
	pixellength = imagewidth * 3;
	while (pixellength % 4 != 0)
		pixellength++;
	pixellength *= imageheight;
	pixeldata = (GLubyte*)malloc(pixellength);
	fseek(pfile, 54, SEEK_SET);
	fread(pixeldata, pixellength, 1, pfile);
	if (!pixeldata)
		return 0;
	fclose(pfile);

	srand(time(NULL) * 1000);
	for (int i = 0; i < 150; ++i) {
		x.push(1.8 * rand() / (RAND_MAX + 1.0) + (-0.9));
		speed.push((0.01) * rand() / (RAND_MAX + 1.0) + 0.006);
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, -1);
	glutInitWindowSize(imagewidth * 3.5, imageheight * 8);
	glutCreateWindow("Game : Coin Catcher");
	glutMouseFunc(&OnMouse);
	glutPassiveMotionFunc(passive);
	glutDisplayFunc(&display);
	glutIdleFunc(&idle);
	glutTimerFunc(1000, timer, 0);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(key);
	glutSpecialUpFunc(key_up);
	glutMainLoop();
}