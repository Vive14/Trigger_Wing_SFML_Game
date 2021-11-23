#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "sfmlAll.h"

class ScoreBoard
{
private:
	struct scoreData
	{
		string name;
		int score;
	};

	Font fontExtra;
	Text namePlayer[5];
	Text scorePlayer[5];

public:
	ScoreBoard();
	bool loadFromFile(string fileName);
	vector<scoreData> data;

	void sequence(); 
	void addScore(string name, int score);
	void uploadFile(string fileName);
	void update();
	void render(RenderWindow& window);
};

