#pragma once
class Card
{
private:
	char c_color;
	int c_number;
public:
	Card(char color = '*', int number = 0);
	char get_color();
	int get_number();
	void set_card(Card card);
};