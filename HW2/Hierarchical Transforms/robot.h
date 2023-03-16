#pragma once
#include<GL/freeglut.h>
#include<iostream>
#define torso 1
#define head 2
#define right_arm 3
#define right_forearm 4
#define left_arm 5
#define left_forearm 6
#define right_thigh 7
#define right_leg 8
#define left_thigh 9
#define left_leg 10
using namespace std;

const float gray[3] = { 0.9, 0.9, 0.9 };
const float purple[3] = { 1, 0, 1 };
const float white[3] = { 1, 1, 1 };
const float black[3] = { 0, 0, 0 };

class Robot {
private:
	int flag = 1, record = 0;
	float torso_x = -30, torso_y = 0,
		head_angle = 0,
		right_arm_angle = 0,
		right_forearm_angle = 0,
		left_arm_angle = 0,
		left_forearm_angle = 0,
		right_thigh_angle = 0,
		right_leg_angle = 0,
		left_thigh_angle = 0,
		left_leg_angle = 0;
	float eyes[8][3] = {
		{-0.1, 2.6, 0.42},
		{-0.25, 2.8, 0.42},
		{-0.1, 2.8, 0.42},
		{-0.25, 2.6, 0.42},
		{0.1, 2.6, 0.42},
		{0.25, 2.8, 0.42},
		{0.1, 2.8, 0.42},
		{0.25, 2.6, 0.42},
	};
	void struct_torso();
	void struct_head();
	void struct_right_arm();
	void struct_right_forearm();
	void struct_left_arm();
	void struct_left_forearm();
	void struct_right_thigh();
	void struct_right_leg();
	void struct_left_thigh();
	void struct_left_leg();
public:
	void init_struct();
	void draw();
	void walk();
	void turn_torso(float, float);
	void turn_head(float);
	void turn_right_arm(float);
	void turn_right_forearm(float);
	void turn_left_arm(float);
	void turn_left_forearm(float);
	void turn_right_thigh(float);
	void turn_right_leg(float);
	void turn_left_thigh(float);
	void turn_left_leg(float);
	int get_record();
	void init_record();
};