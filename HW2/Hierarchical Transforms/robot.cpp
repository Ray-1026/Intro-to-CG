#include"robot.h"

void Robot::struct_torso() {
	glNewList(torso, GL_COMPILE);
	glColor3fv(purple);
	glTranslatef(0, 1, 0);
	glScalef(1.5, 2.5, 1);
	glLineWidth(3);
	glutWireCube(1.0);
	glEndList();
}

void Robot::struct_head() {
	glNewList(head, GL_COMPILE);
	glColor3fv(white);
	glTranslatef(0, 2.63, 0);
	glutSolidCube(0.8);
	glColor3f(0, 0, 0);
	glLineWidth(3);
	glutWireCube(0.8);

	glTranslatef(0, -2.63, 0);
	glColor3fv(black);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex3fv(eyes[0]);
	glVertex3fv(eyes[1]);
	glVertex3fv(eyes[2]);
	glVertex3fv(eyes[3]);
	glVertex3fv(eyes[4]);
	glVertex3fv(eyes[5]);
	glVertex3fv(eyes[6]);
	glVertex3fv(eyes[7]);
	glEnd();
	glEndList();
}

void Robot::struct_right_arm() {
	glNewList(right_arm, GL_COMPILE);
	glColor3fv(purple);
	glLineWidth(3);
	glTranslatef(-1.05, 1.45, 0);
	glScalef(0.5, 1, 0.5);
	glutWireCube(1);

	glColor3fv(gray);
	glTranslatef(0, 0.75, 0);
	glScalef(2, 1 / 0.8, 2);
	glutSolidSphere(0.3, 20, 20);
	glEndList();
}

void Robot::struct_right_forearm() {
	glNewList(right_forearm, GL_COMPILE);
	glColor3fv(gray);
	glTranslatef(-1.05, 0.8, 0);
	glutSolidSphere(0.22, 20, 20);

	glTranslatef(0, -0.65, 0);
	glColor3fv(purple);
	glScalef(0.5, 1, 0.5);
	glutWireCube(1);
	glEndList();
}

void Robot::struct_left_arm() {
	glNewList(left_arm, GL_COMPILE);
	glColor3fv(purple);
	glLineWidth(3);
	glTranslatef(1.05, 1.45, 0);
	glScalef(0.5, 1, 0.5);
	glutWireCube(1);

	glColor3fv(gray);
	glTranslatef(0, 0.75, 0);
	glScalef(2, 1 / 0.8, 2);
	glutSolidSphere(0.3, 20, 20);
	glEndList();
}

void Robot::struct_left_forearm() {
	glNewList(left_forearm, GL_COMPILE);
	glColor3fv(gray);
	glTranslatef(1.05, 0.8, 0);
	glutSolidSphere(0.22, 20, 20);

	glTranslatef(0, -0.65, 0);
	glColor3fv(purple);
	glScalef(0.5, 1, 0.5);
	glutWireCube(1);
	glEndList();
}

void Robot::struct_right_thigh() {
	glNewList(right_thigh, GL_COMPILE);
	glColor3fv(purple);
	glLineWidth(3);
	glTranslatef(-0.5, -1.4, 0);
	glScalef(0.75, 1.2, 1);
	glutWireCube(1);

	glColor3fv(gray);
	glTranslatef(0, 0.65, 0);
	glScalef(1.35, 1.2, 1);
	glutSolidSphere(0.33, 20, 20);
	glEndList();
}

void Robot::struct_right_leg() {
	glNewList(right_leg, GL_COMPILE);
	glColor3fv(gray);
	glTranslatef(-0.5, -2.2, 0);
	glutSolidSphere(0.3, 20, 20);

	glColor3fv(purple);
	glLineWidth(3);
	glTranslatef(0, -0.7, 0);
	glScalef(0.8, 1, 1);
	glutWireCube(1);

	glTranslatef(0, -0.6, 0.1);
	glScalef(1.2, 0.2, 1.25);
	glutWireCube(1);
	glEndList();
}

void Robot::struct_left_thigh() {
	glNewList(left_thigh, GL_COMPILE);
	glColor3fv(purple);
	glLineWidth(3);
	glTranslatef(0.5, -1.4, 0);
	glScalef(0.75, 1.2, 1);
	glutWireCube(1);

	glColor3fv(gray);
	glTranslatef(0, 0.65, 0);
	glScalef(1.35, 1.2, 1);
	glutSolidSphere(0.33, 20, 20);
	glEndList();
}

void Robot::struct_left_leg() {
	glNewList(left_leg, GL_COMPILE);
	glColor3fv(gray);
	glTranslatef(0.5, -2.2, 0);
	glutSolidSphere(0.3, 20, 20);

	glColor3fv(purple);
	glLineWidth(3);
	glTranslatef(0, -0.7, 0);
	glScalef(0.8, 1, 1);
	glutWireCube(1);

	glTranslatef(0, -0.6, 0.1);
	glScalef(1.2, 0.2, 1.25);
	glutWireCube(1);
	glEndList();
}

void Robot::init_struct() {
	struct_torso();
	struct_head();
	struct_right_arm();
	struct_right_forearm();
	struct_left_arm();
	struct_left_forearm();
	struct_right_thigh();
	struct_right_leg();
	struct_left_thigh();
	struct_left_leg();
}

void Robot::draw() {
	//torso
	glPushMatrix();
	glRotatef(torso_x, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(torso_y, 1, 0, 0);
	glTranslatef(0, 0.5, 0);
	glCallList(torso);
	glPopMatrix();

	//head
	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(torso_y, 1, 0, 0);
	glTranslatef(0, 0.5, 0);
	glRotatef(head_angle, 0, 1, 0);
	glPushMatrix();
	glCallList(head);
	glPopMatrix();
	glPopMatrix();

	//upper right arm + lower right arm
	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(torso_y, 1, 0, 0);
	glTranslatef(0, 0.5, 0);
	glTranslatef(-1.05, 2.15, 0);
	glRotatef(right_arm_angle, 1, 0, 0);
	glTranslatef(1.05, -2.15, 0);
	glPushMatrix();
	glCallList(right_arm);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.05, 0.8, 0);
	glRotatef(right_forearm_angle, 1, 0, 0);
	glTranslatef(1.05, -0.8, 0);
	glCallList(right_forearm);
	glPopMatrix();
	glPopMatrix();

	//upper left arm + lower left arm
	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(torso_y, 1, 0, 0);
	glTranslatef(0, 0.5, 0);
	glTranslatef(1.05, 2.15, 0);
	glRotatef(left_arm_angle, 1, 0, 0);
	glTranslatef(-1.05, -2.15, 0);
	glPushMatrix();
	glCallList(left_arm);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.05, 0.8, 0);
	glRotatef(left_forearm_angle, 1, 0, 0);
	glTranslatef(-1.05, -0.8, 0);
	glCallList(left_forearm);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	//upper right leg + lower right leg
	glPushMatrix();
	glTranslatef(-0.5, -0.53, 0);
	glRotatef(right_thigh_angle, 1, 0, 0);
	glTranslatef(0.5, 0.53, 0);
	glPushMatrix();
	glCallList(right_thigh);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -2.2, 0);
	glRotatef(right_leg_angle, 1, 0, 0);
	glTranslatef(0, 2.2, 0);
	glCallList(right_leg);
	glPopMatrix();
	glPopMatrix();

	//upper left leg + lower left leg
	glPushMatrix();
	glTranslatef(0.5, -0.53, 0);
	glRotatef(left_thigh_angle, 1, 0, 0);
	glTranslatef(-0.5, 0.53, 0);
	glPushMatrix();
	glCallList(left_thigh);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -2.2, 0);
	glRotatef(left_leg_angle, 1, 0, 0);
	glTranslatef(0, 2.2, 0);
	glCallList(left_leg);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void Robot::walk() {
	if (record == 0) {
		torso_y = 0;
		right_arm_angle = 0;
		right_forearm_angle = 0;
		left_arm_angle = 0;
		left_forearm_angle = 0;
		right_thigh_angle = 0;
		right_leg_angle = 0;
		left_thigh_angle = 0;
		left_leg_angle = 0;
		record++;
	}
	if (flag) {
		torso_y += 0.5;
		right_arm_angle += 2;
		right_forearm_angle += 0.5;
		left_arm_angle -= 2;
		left_forearm_angle -= 0.5;
		right_thigh_angle -= 1;
		right_leg_angle -= 0.5;
		left_thigh_angle += 1;
		left_leg_angle += 0.5;
		head_angle += 0.5;
	}
	else {
		torso_y -= 0.5;
		right_arm_angle -= 2;
		right_forearm_angle -= 0.5;
		left_arm_angle += 2;
		left_forearm_angle += 0.5;
		right_thigh_angle += 1;
		right_leg_angle += 0.5;
		left_thigh_angle -= 1;
		left_leg_angle -= 0.5;
		head_angle -= 0.5;
	}
	if (right_arm_angle >= 45)
		flag = 0;
	else if (right_arm_angle <= -45)
		flag = 1;
}

void Robot::turn_torso(float x, float y) {
	torso_x += x;
	if (torso_y <= 120 && torso_y >= -120)
		torso_y += y;
	else if (torso_y > 120 && y < 0)
		torso_y += y;
	else if (torso_y < -120 && y > 0)
		torso_y += y;
}

void Robot::turn_head(float x) {
	head_angle += x;
}

void Robot::turn_right_arm(float y) {
	right_arm_angle += y;
}

void Robot::turn_right_forearm(float y) {
	if (y == 5 && right_forearm_angle < 90)
		right_forearm_angle += y;
	else if (y == -5 && right_forearm_angle > -90)
		right_forearm_angle += y;
}

void Robot::turn_left_arm(float y) {
	left_arm_angle += y;
}

void Robot::turn_left_forearm(float y) {
	if (y == 5 && left_forearm_angle < 90)
		left_forearm_angle += y;
	else if (y == -5 && left_forearm_angle > -90)
		left_forearm_angle += y;
}

void Robot::turn_right_thigh(float y) {
	if (y == 5 && right_thigh_angle < 90)
		right_thigh_angle += y;
	else if (y == -5 && right_thigh_angle > -90)
		right_thigh_angle += y;
}

void Robot::turn_right_leg(float y) {
	if (y == 5 && right_leg_angle < 90)
		right_leg_angle += y;
	else if (y == -5 && right_leg_angle > -30)
		right_leg_angle += y;
}

void Robot::turn_left_thigh(float y) {
	if (y == 5 && left_thigh_angle < 90)
		left_thigh_angle += y;
	else if (y == -5 && left_thigh_angle > -90)
		left_thigh_angle += y;
}

void Robot::turn_left_leg(float y) {
	if (y == 5 && left_leg_angle < 90)
		left_leg_angle += y;
	else if (y == -5 && left_leg_angle > -30)
		left_leg_angle += y;
}

int Robot::get_record() {
	return record;
}

void Robot::init_record() {
	record = 0;
}