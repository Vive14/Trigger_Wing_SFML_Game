#include "enterNameText.h"

Textbox::Textbox(int size, Color color, bool selected)
{
	enterNameText.setCharacterSize(size);
	enterNameText.setFillColor(color);
	isSelected = selected;
	if (selected)
	{
		enterNameText.setString("_");
	}
	else
	{
		enterNameText.setString("");
	}
}

void Textbox::setFont(Font& font)
{
	enterNameText.setFont(font);
}

void Textbox::setPosition(Vector2f pos)
{
	enterNameText.setPosition(pos);
}

void Textbox::setLimit(bool TNL, int lim)
{
	textNameLimit = TNL;
	limit = lim - 1;
}

void Textbox::setSelected(bool sel)
{
	isSelected = sel;
	if (!sel)
	{
		string t = text.str();
		string newT = "";
		for (int i = 0; i < t.length(); i++)
		{
			newT += t[i];
		}
		enterNameText.setString(newT);
	}
}

string Textbox::getText()
{
	return text.str();
}

void Textbox::drawTo(RenderWindow& window)
{
	window.draw(enterNameText);
}

void Textbox::typedOn(Event input)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
		{
			if (textNameLimit)
			{
				if (text.str().length() <= limit)
				{
					inputLogic(charTyped);
				}
				else if (text.str().length() > limit && charTyped == DELETE_KEY)
				{
					deleteLastChar();
				}
			}
			else
			{
				inputLogic(charTyped);
			}
		}
	}
}
