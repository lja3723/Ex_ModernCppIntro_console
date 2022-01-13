#ifndef CARD_H
#define CARD_H

#include "Rect.h"
#include <memory>

class Card : public Rect
{
public:
	Card(int, int, int, int);
	Card(int, int);
	virtual ~Card();

	//virtual void draw(Application&) override;
	void flip();

	int getSuit() const;
	int getRank() const;
	bool getFaceUp() const;

	void setSuit(int suit);
	void setRank(int rank);
	void setFaceUp(bool faceUp);

	friend bool operator==(const Card& lhs, const Card& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Card& c);

	static int getCardWidth();
	static int getCardHeight();
	static const int CardWidth = 75;
	static const int CardHeight = 100;

private:
	int suit;
	int rank;
	bool faceUp;
};

extern bool operator==(const Card& lhs, const Card& rhs);
extern std::ostream& operator<<(std::ostream& os, const Card& c);

using CardPtr = std::shared_ptr<Card>;

#endif