#include "stdafx.h"
#include "Card_list.h"

std::list<Card> Card_list::GetCardList()
{
	return m_cardlist;
}
void Card_list::push_card(Card card) {
	m_cardlist.push_back(card);
}
std::list<Card>::iterator Card_list::get_begin_iter() {
	return m_cardlist.begin();
}
int Card_list::card_size() {
	return m_cardlist.size();
}

void Card_list::pop_card() {
	m_cardlist.pop_front();
}
void Card_list::shuffle(int pre, int pos)
{
	if (pos<pre)
	{
		throw "pos must smaller than pre";
	}

	if (pos > this->m_cardlist.size())
	{
		throw "Out of Index";
	}

	srand((unsigned int)time(NULL));

	for (int i = 0; i<100; i++)
	{
		int n = rand() % (pos - pre) + pre;
		int m = rand() % (pos - pre) + pre;

		this->swap(n, m);
	}

}

Card Card_list::get(int i)
{
	if (i > m_cardlist.size() - 1)
	{
		throw "Out of Index";
	}

	typename std::list<Card>::iterator iter;

	iter = m_cardlist.begin();

	for (int j = 0; j<i; j++)
	{
		iter++;
	}

	return *iter;

}
void Card_list::swap(int n, int m)
{

	typename std::list<Card>::iterator iter1 = m_cardlist.begin();
	typename std::list<Card>::iterator iter2 = m_cardlist.begin();

	if (n == 55 || m == 55)
	{
		n--; m--;
	}
	for (int i = 0; i<n; i++)
		iter1++;
	for (int i = 0; i<m; i++)
		iter2++;

	Card tmp = (this->get(n));

	(iter1)->set_card((this->get(m)));
	(iter2)->set_card(tmp);

}

