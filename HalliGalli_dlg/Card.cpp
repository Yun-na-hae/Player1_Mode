#include "stdafx.h"
#include "Card.h"
Card::Card(char color, int number)
{
	this->c_color = color;
	this->c_number = number;
}

void Card::set_card(Card card)
{
	this->c_color = card.get_color();
	this->c_number = card.get_number();
}

char Card::get_color()
{
	return this->c_color;
}

int Card::get_number()
{
	return this->c_number;
}


