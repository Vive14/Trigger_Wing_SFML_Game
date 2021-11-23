#pragma once

#include <sstream>
#include <iostream>
#include "sfmlAll.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox
{
private:
	Text enterNameText; 
	ostringstream text;

	void inputLogic(int keyTyped)
	{
		if (keyTyped != DELETE_KEY && keyTyped != ENTER_KEY && keyTyped != ESCAPE_KEY)
		{
			text << static_cast<char>(keyTyped);
		}
		else if (keyTyped == DELETE_KEY)
		{
			if (text.str().length() > 0) { deleteLastChar(); }
		}
		enterNameText.setString(text.str() + "_");
	}

	void deleteLastChar()
	{
		string t = text.str();
		string newNameText = "";
		for (int i = 0; i < t.length() - 1; i++)
		{
			newNameText += t[i];
		}
		text.str("");
		text << newNameText;
		enterNameText.setString(text.str());
	}

public:
	bool isSelected = false;
	bool textNameLimit = false;
	int limit;

	string getText();

	Textbox(int size, Color color, bool selected);

	void setFont(Font& font);
	void setPosition(Vector2f position);
	void setLimit(bool TeNaLi, int lim);
	void setSelected(bool sel);

	void drawTo(RenderWindow& window);
	void typedOn(Event input);
};

