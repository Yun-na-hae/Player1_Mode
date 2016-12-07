#include "stdafx.h"
#include "Main.h"


Main::Main()
{
}


Main::~Main()
{
}

void Main::Game_ready()
{

	p1_win = p2_win = 0;

	char color[4] = { 'G','Y','B','R' };
	std::list<Card> tmplist;
	
	//모든 카드 초기화
	for (int i = 0; i<4; i++)
		for (int j = 0; j<5; j++)
		{
			Card card(color[i], 1);
			All_cards.push_card(card);
		}

	for (int i = 0; i<4; i++)
		for (int j = 0; j<3; j++)
		{
			Card card(color[i], 2);
			All_cards.push_card(card);
		}

	for (int i = 0; i<4; i++)
		for (int j = 0; j<3; j++)
		{
			Card card(color[i], 3);
			All_cards.push_card(card);
		}

	for (int i = 0; i<4; i++)
		for (int j = 0; j<2; j++)
		{
			Card card(color[i], 4);
			All_cards.push_card(card);
		}

	for (int i = 0; i<4; i++)
		for (int j = 0; j<1; j++)
		{
			Card card(color[i], 5);
			All_cards.push_card(card);
		}

	int advasfa = 234;
	//모든 카드 섞기
	All_cards.shuffle(0, 55);

	//Player 1과 Player 2에게 28장씩 분배
	for (int i = 0; i < 28; i++)
	{
		P1_cards.push_card(All_cards.get(0));
		All_cards.pop_card();
		P2_cards.push_card(All_cards.get(0));
		All_cards.pop_card();
	}
	
}

void Main::Game_start()
{
	std::list<Card>::iterator iter_p1 = P1_cards.get_begin_iter();
	std::list<Card>::iterator iter_p2 = P2_cards.get_begin_iter();

	Card p1 = *(iter_p1);
	Card p2 = *(iter_p2);

	P1_cards.pop_card();
	P2_cards.pop_card();

	All_cards.push_card(p1);
	All_cards.push_card(p2);
}

bool Main::Compare(Card a, Card b)
{
	if (a.get_color() == b.get_color())
    {
		if ((a.get_number() + b.get_number()) == 5)
			return 1;
     else
         return 0;
    } else {
    if (a.get_number() == 5 || b.get_number() == 5)
        return 1;
    else
        return 0;
    }
}