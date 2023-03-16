#define _CRT_SECURE_NO_WARNINGS
#include"robot.h"

int lastx = 0, lasty = 0;
float rotatex = 0, rotatey = 0, light1 = 0, light2 = 0;
string instruct[11] = {
	"Q/q : turn torso.",
	"W/w : turn head.",
	"E/e : turn right arm.", 
	"R/r : turn right forearm.",
	"T/t : turn left arm.",
	"A/a : turn left forearm.",
	"S/s : turn right thigh.", 
	"D/d : turn right leg.",
	"F/f : turn left thigh,",
	"G/g : turn left leg.",
	"keep pressing \"z\" : walk"
};
Robot robot;

void write(string str, GLfloat x, GLfloat y) {
	int len, i;
	glRasterPos2f(x, y);
	len = str.size();
	for (i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
}

void display() {
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0, 1, 1);
	for (int i = 0; i < 11; i++)
		write(instruct[i], -6.5, 6.7 - i * 0.5);

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(rotatex * -1, 0, 1, 0);
	glRotatef(rotatey, 1, 0, 0);

	robot.draw();

	glPopMatrix();
	glutSwapBuffers();
}

void idle() {
	display();
}

void mouse(int btn, int state, int x, int y) {
	lastx = x;
	lasty = y;
}

void motion(int x, int y) {
	int dx = x - lastx, dy = y - lasty;
	rotatex -= (float)dx * 0.5;
	if (rotatex > 360.0)
		rotatex -= 360.0;
	if (rotatex < 0)
		rotatex = 360;
	rotatey += (float)dy * 0.5;
	lastx = x;
	lasty = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
		robot.turn_torso(0, 10);
		break;
	case 'Q':
		robot.turn_torso(0, -10);
		break;
	case 'w':
		robot.turn_head(5);
		break;
	case 'W':
		robot.turn_head(-5);
		break;
	case 'e':
		robot.turn_right_arm(5);
		break;
	case 'E':
		robot.turn_right_arm(-5);
		break;
	case 'r':
		robot.turn_right_forearm(5);
		break;
	case 'R':
		robot.turn_right_forearm(-5);
		break;
	case 't':
		robot.turn_left_arm(5);
		break;
	case 'T':
		robot.turn_left_arm(-5);
		break;
	case 'a':
		robot.turn_left_forearm(5);
		break;
	case 'A':
		robot.turn_left_forearm(-5);
		break;
	case 's':
		robot.turn_right_thigh(5);
		break;
	case 'S':
		robot.turn_right_thigh(-5);
		break;
	case 'd':
		robot.turn_right_leg(5);
		break;
	case 'D':
		robot.turn_right_leg(-5);
		break;
	case 'f':
		robot.turn_left_thigh(5);
		break;
	case 'F':
		robot.turn_left_thigh(-5);
		break;
	case 'g':
		robot.turn_left_leg(5);
		break;
	case 'G':
		robot.turn_left_leg(-5);
		break;
	case 'z':
		robot.walk();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

void key_up(unsigned char key, int x, int y) {
	if (key == 'z') {
		robot.init_record();
	}
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, (GLfloat)w / (GLfloat)h, 1, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, -0.5, -8);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("½²®vºÍ");
	robot.init_struct();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(key_up);
	glutMainLoop();
}

