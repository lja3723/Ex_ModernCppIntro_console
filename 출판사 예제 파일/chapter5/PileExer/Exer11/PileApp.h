// ���� ���� 2�� 3�� ������Ŵ
// std::list�� ����ؼ� ���� ���� 3�� �ٽ� �ۼ�
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