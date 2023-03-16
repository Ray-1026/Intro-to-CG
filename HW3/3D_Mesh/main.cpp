#include<GL/freeglut.h>
#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#define path "..\\obj\\Dino.obj"
using namespace std;
const float PI = 3.1415926 / 180.0;

class Obj {
private:
	struct vertex {
		GLfloat x, y, z;
	};
	vector<vertex> v;
	vector<vector<GLint>> f;
	GLfloat dino_amb[4] = { 0.24725, 0.1995, 0.0745, 1 },
		dino_dif[4] = { 0.75164, 0.60648, 0.22648, 1 },
		dino_spec[4] = { 0.628281, 0.555802, 0.366065, 1 },
		dino_shine = 0.5,
		mat_amb[4] = { 0.0215, 0.1745, 0.0215, 1 },
		mat_dif[4] = { 0.07568, 0.61424, 0.07568, 1 },
		mat_spec[4] = { 0.633, 0.727811, 0.633, 1 },
		mat_shine = 0.6;
public:
	Obj(string file) {
		ifstream input(file);
		string text;
		while (getline(input, text)) {
			if (text.substr(0, 1) == "v") {
				GLfloat x, y, z;
				istringstream ss(text.substr(2));
				ss >> x >> y >> z;
				x /= 150.0;
				y /= 150.0;
				z /= 150.0;
				v.push_back({ x, y, z });
			}
			else if (text.substr(0, 1) == "f") {
				GLint u, v, w;
				istringstream ss(text.substr(2));
				ss >> u >> v >> w;
				f.push_back({ u - 1, v - 1, w - 1 });
			}
		}
		input.close();
	}
	void draw() {
		{
			glMaterialfv(GL_FRONT, GL_AMBIENT, dino_amb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, dino_dif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, dino_spec);
			glMaterialf(GL_FRONT, GL_SHININESS, dino_shine);
			glBegin(GL_TRIANGLES);
			for (int i = 0; i < f.size(); i++) {
				vertex a, b, c;
				GLint first = f[i][0], second = f[i][1], third = f[i][2];
				a.x = v[first].x;
				a.y = v[first].y;
				a.z = v[first].z;

				b.x = v[second].x;
				b.y = v[second].y;
				b.z = v[second].z;

				c.x = v[third].x;
				c.y = v[third].y;
				c.z = v[third].z;

				GLfloat vec1[3] = { a.x - b.x, a.y - b.y, a.z - b.z },
					vec2[3] = { a.x - c.x, a.y - c.y, a.z - c.z },
					vec3[3] = { vec1[1] * vec2[2] - vec1[2] * vec2[1], vec2[0] * vec1[2] - vec2[2] * vec1[0] , vec2[1] * vec1[0] - vec2[0] * vec1[1] },
					d = sqrt(vec3[0] * vec3[0] + vec3[1] * vec3[1] + vec3[2] * vec3[2]),
					normal[3] = { vec3[0] / d, vec3[1] / d, vec3[2] / d };
				glNormal3f(normal[0], normal[1], normal[2]);
				glVertex3f(a.x, a.y, a.z);
				glVertex3f(b.x, b.y, b.z);
				glVertex3f(c.x, c.y, c.z);
			}
			glEnd();
		}

		{
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec);
			glMaterialf(GL_FRONT, GL_SHININESS, mat_shine);
			glLineWidth(3);
			glutWireSphere(0.5, 15, 15);
		}
	}
};

class TrackBall {
public:
	float alpha = 0, beta = 90;
	int lastx = 0, lasty = 0;
	void cal(int x, int y) {
		float tempa = (float)(x - lastx) / 5.0, tempb = (float)(lasty - y) / 3.0;
		alpha -= tempb;
		beta += tempa;
		if (alpha > 360)
			alpha -= 360;
		else if (alpha < -360)
			alpha += 360;
		if (beta > 360)
			beta -= 360;
		else if (beta < -360)
			beta += 360;
		lastx = x;
		lasty = y;
	}
};

Obj dino(path);
TrackBall ball;

void init() {
	GLfloat light_amb[4] = { 0.5, 0.5, 0.5, 1 },
		light_dif[4] = { 0.5, 0.5, 0.5, 1 },
		light_spec[4] = { 0.7, 0.7, 0.7, 1 },
		light_pos[4] = { -5, 5, 0, 1 },
		light2_amb[4] = { 0, 0, 0, 1 },
		light2_dif[4] = { 0.3, 0.3, 0.3, 1 },
		light2_spec[4] = { 0.3, 0.3, 0.3, 1 },
		light2_pos[4] = { 1, 1, 5, 1 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	glLightfv(GL_LIGHT1, GL_AMBIENT, light2_amb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light2_dif);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light2_spec);
	glLightfv(GL_LIGHT1, GL_POSITION, light2_pos);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}

GLint angle = 0;

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	init();
	glPushMatrix();
	gluLookAt(cos(ball.alpha * PI) * cos(ball.beta * PI), sin(ball.alpha * PI), cos(ball.alpha * PI) * sin(ball.beta * PI), 0, 0, 0, -1 * sin(ball.alpha * PI) * cos(ball.beta * PI), cos(ball.alpha * PI), -1 * sin(ball.alpha * PI) * sin(ball.beta * PI));
	dino.draw();
	glPopMatrix();
	glutSwapBuffers();
}

void idle() {
	angle += 1;
	angle %= 360;
	display();
}

void mouse(int btn, int state, int x, int y) {
	if (btn == GLUT_RIGHT_BUTTON)
		exit(0);
	if (btn == GLUT_LEFT_BUTTON) {
		ball.lastx = x;
		ball.lasty = y;
	}
}

void motion(int x, int y) {
	ball.cal(x, y);
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1, 50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -0.5);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("3D Mesh");
	glEnable(GL_DEPTH_TEST);
	init();
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutMainLoop();
}
