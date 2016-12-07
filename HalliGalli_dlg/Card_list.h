#pragma once
#include "Card.h"

class Card_list
{
public:
	std::list<Card> GetCardList();
	void Card_list::shuffle(int pre, int pos);
	Card get(int i);
	void Card_list::swap(int n, int m);
	void Card_list::push_card(Card card);
	std::list<Card>::iterator get_begin_iter();
	void Card_list::pop_card();

	int Card_list::card_size();
private:
	std::list<Card> m_cardlist;
};

