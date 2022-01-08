// 응용 과제 2과 3을 발전시킴
// std::list를 사용해서 응용 과제 3을 다시 작성
#pragma once
#include "pclaf.h"
#include "Pile.h"

class PileApp : public Application
{
public:
	PileApp(const TCHAR*);
	PileApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	// Exer
	void mouseRDown(int, int);
	void paint();
	// data fields
	DeckPile theDeck{ 100, 100 };
	CardPile theDiscard{ 200, 100 };
};