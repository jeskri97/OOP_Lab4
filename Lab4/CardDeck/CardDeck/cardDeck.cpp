
#include <iostream>
#include <string>

class Card {
private:
	std::string suit;
	int rank;
public:
	void setVal(std::string suit, int rank) {
		this->suit = suit;
		this->rank = rank;
		//printf("Created card rank %i of %s\n", rank, suit.c_str());
	}

	void print() {
		if (suit == "Joker")
			printf("%s\n", suit.c_str());
		else {
			switch (rank)
			{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				printf("%i of ", rank + 1);
				break;
			case 10:
				printf("Jack of ");
				break;
			case 11:
				printf("Queen of ");
				break;
			case 12:
				printf("King of ");
				break;
			case 13:
				printf("ACE of ");
				break;
			default:
				break;
			}
			printf("%s\n", suit.c_str());
		}
	}
};

class CardDeck {
private:
	Card cards[56];
public:
	CardDeck() {
		int index = 0;
		for (int i = 1; i < 14; i++) {
			this->cards[index].setVal("Clubs", i);
			index++;
		}
		for (int i = 1; i < 14; i++) {
			this->cards[index].setVal("Diamonds", i);
			index++;
		}
		for (int i = 1; i < 14; i++) {
			this->cards[index].setVal("Hearts", i);
			index++;
		}
		for (int i = 1; i < 14; i++) {
			this->cards[index].setVal("Spades", i);
			index++;
		}
		for (int i = 0; i <= 3; i++) {
			cards[index].setVal("Joker", 1);
			index++;
		}
	}

	//CardDeck(Card* cards) {
	//	this->cards = cards;
	//}

	void print() {
		printf("-----< Start >------------------------------\n");
		for (int i = 0; i < 55; i++) {
			cards[i].print();
		}
		printf("-----< End >--------------------------------\n");
	}
};