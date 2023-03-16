#pragma once
#include<GL/freeglut.h>
#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<string>
#include<cmath>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

const GLdouble PI = 3.1415926;

class Draw {
public:
	void write(string, GLfloat, GLfloat);
	void circle(GLfloat, GLfloat, GLfloat);
	void line(GLfloat, GLfloat, GLfloat, GLfloat);
};