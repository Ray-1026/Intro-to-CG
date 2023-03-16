#pragma once
#include"draw.h"
#include<fstream>
using namespace std;

class Background :public Draw {
private:
	float loading_time = 0;
	int highest_score;
public:
	int menu = 0, score = 0, flag = 1, gamestatus = 1, time = 90, count;
	Background();
	void start();
	void loading();
	void game_background(GLint, GLint, GLubyte*);
	void over();
	void changeStatus();
};