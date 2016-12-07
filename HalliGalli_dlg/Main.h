#pragma once
#include "Card_list.h"
class Main
{
public:
	Main();
	~Main();
public:
	Card_list All_cards, P1_cards, P2_cards;	//전역변수 설정
	bool p1_win, p2_win;	//누가 이겼는 지 
public:
	void Game_ready();
	void Game_start();
	bool Compare(Card a, Card b);
};

