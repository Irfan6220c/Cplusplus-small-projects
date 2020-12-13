//My take on blackjack game

#include <iostream>
#include <vector>
#include <array>
#include <ctime>
#include <algorithm>
#include <random>
#include <string>

enum Card_Rank
{
    Rank_2,
    Rank_3,
    Rank_4,
    Rank_5,
    Rank_6,
    Rank_7,
    Rank_8,
    Rank_9,
    Rank_10,
    Rank_Jack,
    Rank_King,
    Rank_Queen,
    Rank_Ace,
    Total_Card_Rank
};

enum Card_Suits
{
    Suits_Clubs,
    Suits_Diamonds,
    Suits_Hearts,
    Suits_Spades,
    Tota_count_Suits

};

struct Card
{
    Card_Rank m_Rank;
    Card_Suits m_Suits;
};

void PrintCard(const Card &card) 

{
    switch (card.m_Rank)
    {
    case Rank_2:
        std::cout << "2";
        break;
    case Rank_3:
        std::cout << "3";
        break;
    case Rank_4:
        std::cout << "4";
        break;
    case Rank_5:
        std::cout << "5";
        break;
    case Rank_6:
        std::cout << "6";
        break;
    case Rank_7:
        std::cout << "7";
        break;
    case Rank_8:
        std::cout << "8";
        break;
    case Rank_9:
        std::cout << "9";
        break;
    case Rank_10:
        std::cout << "10";
        break;
    case Rank_Jack:
        std::cout << "J";
        break;
    case Rank_Queen:
        std::cout << "Q";
        break;
    case Rank_King:
        std::cout << "K";
        break;
    case Rank_Ace:
        std::cout << "A";
        break;
    default:
        break;
    }

    switch (card.m_Suits)
    {
    case Suits_Clubs:
        std::cout << "C "<<'\n';
        break;
    case Suits_Diamonds:
        std::cout << "D "<<'\n';
        break;
    case Suits_Spades:
        std::cout << "S "<<'\n';
        break;
    case Suits_Hearts:
        std::cout << "H " << '\n';
        break;
    default:
        break;
    }


}


using array= std::array <Card, 52> ;


array cardDeck() {

    array m_Deck {};
    unsigned int Array_index{ 0 };
    for (int i = 0; i < Total_Card_Rank; ++i)
        for (int j = 0; j < Tota_count_Suits; ++j)
        {

            m_Deck[Array_index].m_Rank = static_cast <Card_Rank> (i);
            m_Deck[Array_index].m_Suits = static_cast <Card_Suits> (j);
             
            ++Array_index;
        }
    {

    }

    return m_Deck;
}

void printDeck(const array &Deck) {

    for (auto i:Deck )

    {
        PrintCard(i);
    }


}

array shuffleDeck(array &Deck) {


    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(Deck.begin(), Deck.end(), mt);
    return Deck;
}

int  getCardValue(const Card &card)
{

    switch (card.m_Rank)
    {
    case Rank_2:
        return 2;
        break;
    case Rank_3:
        return 3;
        break;
    case Rank_4:
        return 4;
        break;
    case Rank_5:
        return 5;
        break;
    case Rank_6:
        return 6;
        break;
    case Rank_7:
        return 7;
        break;
    case Rank_8:
        return 8;
        break;
    case Rank_9:
        return 9;
        break;
    case Rank_10:
        return 10;
        break;
    case Rank_Jack:
        return 10;
        break;
    case Rank_Queen:
        return 10;
        break;
    case Rank_King:
        return 10;
        break;
    case Rank_Ace:
        return 11;
        break;
    default:
        break;
    }

}


int Deck_Index{ 0 };

struct Player
{
    int Total_Score{};
    int Number_Cards{};
}; 

using string = std::string;

string choice;

void Cal_Score(Player &Pl, array &Deck) {

    for (int i = 0; i < Pl.Number_Cards; ++i)
    {
      Pl.Total_Score += getCardValue(Deck[Deck_Index]);
      ++Deck_Index;
    }
}

void  Player_turn(array &Deck, bool choice, Player &Player)
{
    if (choice)
    {
        Cal_Score(Player, Deck);
    }
    else if (choice == false)
    {
        Cal_Score(Player,Deck);
    }
}


void Player_turn(Player &Player, array & Deck) {
    std::cout << "The player goes first: " << '\n';
    std::cout << "You can either stand or Hit. Choose (S/H): " << '\n';
    std::cin >> choice;
    if (choice == "S")
    {
        Cal_Score(Player, Deck);

    }
    else if (choice == "H")
    {
        Player.Number_Cards += 1;
        Cal_Score(Player, Deck);
    }
    std::cout << " The total score of player is: " << Player.Total_Score << '\n';
    
}


void Dealer_turn(Player &player,array &Deck) {
    std::cout << " Now the dealer goes after the player" << '\n';
    do
    {
        Cal_Score(player, Deck);
    } while (player.Total_Score<=16);
    std::cout << " The total score of dealer is: " << player.Total_Score << '\n';

}

bool score_compare(Player &PL1, Player &PL2) {
    if (PL1.Total_Score>21)
    {
        return false;
    }
    else if (PL2.Total_Score>21)
    {
        return true;
    }
    else
    {
        return (PL1.Total_Score > PL2.Total_Score ? true : false);
    }


}

int main()
{
    bool result;
    array Card_array;
    Card_array = cardDeck();
    Card_array = shuffleDeck(Card_array);
    printDeck(Card_array);
    Player Dealer; // Initializing player dealer
    Player Player; //Initializing player player
    Dealer.Number_Cards = { 1 }; // Assigning Dealer 1 card
    Player.Number_Cards = { 2 }; // Assigning Player 2 cards
    Player_turn(Player, Card_array);
    Dealer_turn(Dealer, Card_array);

    result=score_compare(Player, Dealer);

    if (result == true)
    {
        std::cout << "the player won:";
    }
    else
    {
        std::cout << "the dealer won:";
    }


    return 0;
}