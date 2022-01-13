#include "Card.h"
//#include "pclaf.h"
Card::Card(int posX, int posY, int _suit, int _rank)
	: Rect(posX, posY, posX + CardWidth, posY + CardHeight),
	suit(_suit), rank(_rank), faceUp(false)
{}
Card::Card(int _suit, int _rank)
	:suit(_suit), rank(_rank), faceUp(false)
{
}
Card::~Card()
{
}

//void Card::draw(Application& app)
//{
//	Rect::draw(app);
//
//	if (faceUp)
//	{
//		if (suit == 1 || suit == 4)
//			app.setTextColor(brightRed);
//		else
//			app.setTextColor(black);
//
//		app.wout << setpos(upperLeftX + 5, upperLeftY + 5);
//		if (suit == 1)
//			app.wout << TEXT("heart");
//		else if (suit == 2)
//			app.wout << TEXT("club");
//		else if (suit == 3)
//			app.wout << TEXT("spade");
//		else if (suit == 4)
//			app.wout << TEXT("diamond");
//
//		app.wout << setpos(upperLeftX + 5, upperLeftY + 20);
//		if (rank == 1)
//			app.wout << TEXT("ace");
//		else if (rank == 11)
//			app.wout << TEXT("jack");
//		else if (rank == 12)
//			app.wout << TEXT("queen");
//		else if (rank == 13)
//			app.wout << TEXT("king");
//		else
//			app.wout << rank;
//	}
//	else
//	{
//		app.wout << setpos(upperLeftX + 30, upperLeftY + 38);
//		app.wout << TEXT("Back");
//		app.line(upperLeftX, upperLeftY, lowerRightX, lowerRightY);
//		app.line(lowerRightX, upperLeftY, upperLeftX, lowerRightY);
//	}
//}

void Card::flip()
{
	faceUp = !faceUp;
}

int Card::getSuit() const
{
	return suit;
}
int Card::getRank() const
{
	return rank;
}
bool Card::getFaceUp() const
{
	return faceUp;
}

void Card::setSuit(int suit)
{
	this->suit = suit;
}
void Card::setRank(int rank)
{
	this->rank = rank;
}
void Card::setFaceUp(bool faceUp)
{
	this->faceUp = faceUp;
}

int Card::getCardWidth()
{
	return CardWidth;
}
int Card::getCardHeight()
{
	return CardHeight;
}

bool operator==(const Card& lhs, const Card& rhs)
{
	return (lhs.suit == rhs.suit) && (lhs.rank == rhs.rank);
}
std::ostream& operator<<(std::ostream& os, const Card& c)
{
	static const char* suitName[] = { "", "heart", "club", "spade", "diamond" };
	static const char* rankName[] = { "", "ace", "jack", "queen", "king" };
	static const auto rankNameSelector = [](int rank) {
		if (rank == 1)
			return rank;
		else if (11 <= rank && rank <= 13)
			return rank - 9;
		else
			return 0;
	};

	os << "À§Ä¡:(" << c.upperLeftX << ", " << c.upperLeftY << ") ";

	if (!c.faceUp)
		os << "µÞ¸é";
	else
	{
		os << suitName[c.suit] << " ";
		if (2 <= c.rank && c.rank <= 10)
			os << c.rank;
		else
			os << rankName[rankNameSelector(c.rank)];
	}

	return os;
}
