// 응용 과제 3을 발전시킴
// 실행 중 마우스 버튼을 더블 클릭하면
// 디스카드 파일이 소유한 카드들의 숫자의 합을
// (100, 250) 점에 표시
// CardPile에 sumRank 멤버 함수 추가
// accumulate, lambda
#pragma once
#include "pclaf.h"
#include "Pile.h"

class PileApp : public Application
{
public:
	PileApp(const TCHAR*);
	PileApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void mouseRDown(int, int);
	// Exer
	void doubleClick(int, int);
	void paint();
	// data fields
	DeckPile theDeck{ 100, 100 };
	CardPile theDiscard{ 200, 100 };
};