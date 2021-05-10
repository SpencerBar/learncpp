#include <iostream>
#include <array>
#include <algorithm> // for std::shuffle
#include <ctime> // for std::time
#include <random> // for std::mt1993

enum class CardRank
	{
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_j,
		rank_q,
		rank_k,
		rank_a,

		rank_max
	};

enum class CardSuit
	{
		suit_clubs,
		suit_heart,
		suit_diamonds,
		suit_spades,

		suit_max,
	};
	
struct Card
{
	CardRank rank{};
	CardSuit suit{};
};

struct Player
{
	int score{};
	int ace{};
	int set{};
};

constexpr int MaxScore{ 21 };
constexpr int MinDealerScore{ 17 };

void PrintCard(const Card & Card)
{
	switch (Card.rank)
	{
	case CardRank::rank_2:		std::cout << '2'; break;
	case CardRank::rank_3:		std::cout << '3'; break;
	case CardRank::rank_4:		std::cout << '4'; break;
	case CardRank::rank_5:		std::cout << '5'; break;
	case CardRank::rank_6:		std::cout << '6'; break;
	case CardRank::rank_7:		std::cout << '7'; break;
	case CardRank::rank_8:		std::cout << '8'; break;
	case CardRank::rank_9:		std::cout << '9'; break;
	case CardRank::rank_10:		std::cout << 'T'; break;
	case CardRank::rank_j:		std::cout << 'J'; break;
	case CardRank::rank_q:		std::cout << 'Q'; break;
	case CardRank::rank_k:		std::cout << 'K'; break;
	case CardRank::rank_a:		std::cout << 'A'; break;
	default:
		std::cout << '?';
		break;
	}

	switch (Card.suit)
	{
	case CardSuit::suit_clubs:		std::cout << 'C'; break;
	case CardSuit::suit_diamonds:	std::cout << 'D'; break;
	case CardSuit::suit_heart:		std::cout << 'H'; break;
	case CardSuit::suit_spades:	std::cout << 'S'; break;
	default:
		std::cout << '?';
		break;
	}
}

using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

deck_type CreateDeck()
{
	deck_type Deck{};
	index_type Card{0};

	auto suits{ static_cast<int>(CardSuit::suit_max) };
	auto ranks{ static_cast<int>(CardRank::rank_max) };

	for (int suit{ 0 }; suit < suits; ++suit)
	{
		for (int rank{ 0 }; rank < ranks; ++rank)
		{
			Deck[Card].suit = static_cast<CardSuit>(suit);
			Deck[Card].rank = static_cast<CardRank>(rank);
			++Card;
		}
	}
	return Deck;
}

void PrintDeck(const deck_type& Deck) 
{
	for (auto& Card : Deck)
	{
		PrintCard(Card);
		std::cout << ' ';
	}
	std::cout << '\n';
}

void ShuffleDeck(deck_type& Deck)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::shuffle(Deck.begin(), Deck.end(), mt);


}

int GetCardValue(const Card& Card)
{
	
	if (Card.rank <= CardRank::rank_10)
	{
		return (static_cast<int>(Card.rank) + 2);
	}
	switch (Card.rank)
	{
	case CardRank::rank_10:		
	case CardRank::rank_j:		
	case CardRank::rank_q:		
	case CardRank::rank_k:		
		return 10;
	case CardRank::rank_a:
		return 11;
	default:
	return 0;
	}
}

bool PlayerWantsHit()
{
	while (true)
	{
		std::cout << "Type 'H' to Hit, or 'S' to Stay: ";
		char HorS{};
		std::cin >> HorS;
		switch (HorS)
		{
		case 'H':
		case 'h':
			return true;
		case 'S':
		case 's':
			return false;
		}
	}
}
bool PlayerTurn(const deck_type& BJDeck, index_type& NextCardIndex, Player& Player) // takes deck ref, the index ref, and player ref
{
	
	while (true) // loops untill false
	{
		if (Player.score > MaxScore) // stops loop if max score reached (21+)
		{
			std::cout << "You Busted yo nut." << '\n';
			return true;
		}
		else
		{
			if (PlayerWantsHit()) // asks player each iteration whether they want to hit it or not
			{
				int CardValue{ GetCardValue(BJDeck[NextCardIndex++]) };
				if (CardValue == 11)
				{
					Player.ace += 1;
				}
				if (Player.score + CardValue > MaxScore)
				{
					if (Player.ace > 0)
					{
						Player.score -= 10;
						Player.ace -= 1;
						std::cout << "You turned an ace from 11 to 1 and now has a score of " << Player.score << '\n';
					}
				}
				Player.score += CardValue;
				std::cout << "You were dealt a " << CardValue << " and now have a score of " << Player.score << '\n';
			}
			else
			{
				std::cout << "You didn't bust your nut, lets hope thats enough!" << '\n';
				return false; // when player doesnt hit any further
			}
			
		}
	}
	
}



bool DealerTurn(const deck_type& BJDeck, index_type& NextCardIndex, Player& Dealer) // takes references of deck, card index and dealer player.
{
	while (Dealer.score < MinDealerScore) // makes dealer keep hitting till min dealer score is reached
	{
		int CardValue{ GetCardValue(BJDeck[NextCardIndex++]) };
		if (CardValue == 11)
		{
			Dealer.ace += 1;
		}
		if (Dealer.score + CardValue > MaxScore)
		{
			if (Dealer.ace > 0)
			{
				Dealer.score -= 10;
				Dealer.ace -= 1;
			}
		}
			Dealer.score += CardValue;
			std::cout << "The Dealer pulled a " << CardValue << " and has a score of " << Dealer.score << '\n';
	}
	

		if (Dealer.score > MaxScore)
		{
			std::cout << "The Dealer has Busted his nut" << '\n';
			return true;
		}
	return false;
}

bool PlayBlackjack(const deck_type& BJDeck, Player& Player1, Player& Dealer)
{
	
		index_type NextCardIndex{ 0 };
	Dealer.score = GetCardValue(BJDeck[NextCardIndex++]);

	std::cout << "The dealer is showing " << Dealer.score << '\n';
	Player1.score = GetCardValue(BJDeck[NextCardIndex]) + GetCardValue(BJDeck[NextCardIndex + 1]) ;
	NextCardIndex += 2;

	std::cout << "You have a score of " << Player1.score << '\n';
	std::cout << "Your Turn!!" << '\n';
	if (PlayerTurn(BJDeck, NextCardIndex, Player1))
	{
		// The player went bust.
		return false;
	}
	std::cout << "Dealers turn!!" << '\n';
	if (DealerTurn(BJDeck, NextCardIndex, Dealer))
	{
		// The dealer went bust, the player wins.
		return true;
	}
	return (Player1.score > Dealer.score);
}


int main()
{
	deck_type Deck{ CreateDeck() };
	Player Player1{};
	Player Dealer{};

	while (Player1.set < 3 || Dealer.set < 3)
	{
		ShuffleDeck(Deck);

		if (PlayBlackjack(Deck, Player1, Dealer))
		{
			std::cout << "You win!" << '\n' << "Congratulations!" << '\n' << '\n';
			++Player1.set;
		}
		else
		{
			std::cout << "The dealer won!" << '\n' << "Oh no! You lost!" << '\n' << '\n';
			++Dealer.set;
		}
		std::cout << "The set score is Player: " << Player1.set << " to Dealer: " << Dealer.set << '\n';
	}

	
	//PrintDeck(Deck);

	return 0;
}