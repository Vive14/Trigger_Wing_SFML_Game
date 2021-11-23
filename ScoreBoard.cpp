#include "ScoreBoard.h"

ScoreBoard::ScoreBoard()
{
	fontExtra.loadFromFile("Fonts/Rockstar-ExtraBold.otf");

	for (int i = 0; i < 5; i++)
	{
		namePlayer[i].setFont(fontExtra);
		namePlayer[i].setCharacterSize(50);
		namePlayer[i].setPosition(Vector2f(65, 501 + i * 80));

		scorePlayer[i].setFont(fontExtra);
		scorePlayer[i].setCharacterSize(50);
		scorePlayer[i].setPosition(Vector2f(340, 502 + i * 80));
	}
}

bool ScoreBoard::loadFromFile(string fileName)
{
	ifstream file(fileName);
	if (file.bad()) { return false; }
	data.clear();

	for (int i = 0; i < 5; i++)
	{
		string strName;
		string strScore;
		if (!getline(file, strName)) { break; }
		if (!getline(file, strScore)) { break; }
		data.push_back(scoreData{ strName , stoi(strScore) }); 
	}
	file.close();
	return true;
}

void ScoreBoard::sequence()
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = i + 1; j < data.size(); j++)
		{
			if (data[i].score < data[j].score)
			{
				scoreData temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
}

void ScoreBoard::addScore(string name, int score)
{
	data.push_back(scoreData{ name, score });
	sequence();
}

void ScoreBoard::uploadFile(string fileName)
{
	fstream file(fileName, ios::out);
	for (int i = 0; i < data.size() && i < 5; i++)
	{
		file << data[i].name << endl << data[i].score << endl;
	}
	file.close();
}

void ScoreBoard::update()
{
	loadFromFile("score.txt");
	sequence();
	for (int i = 0; i < data.size(); i++)
	{
		namePlayer[i].setString(data[i].name);
		scorePlayer[i].setString(to_string(data[i].score));
	}
	uploadFile("score.txt");
}

void ScoreBoard::render(RenderWindow& window)
{
	for (int i = 0; i < 5; i++)
	{
		window.draw(namePlayer[i]);
		window.draw(scorePlayer[i]);
	}
}
