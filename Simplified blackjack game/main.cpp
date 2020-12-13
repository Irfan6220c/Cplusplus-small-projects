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


void playBlackjack(array& Deck)
{
    

    array Player;
    array Dealer;
    std::string choice{};
    int Player_Score{ 0 };
    int Dealer_Score{ 0 };
    int Deck_Index{ 0 };
    int Player_Index{ 0 };
    int Dealer_Index{ 0 };

    std::cout << "The dealer got the following cards:" << '\n';
    for (int i = 0; i < 1; ++i)
    {
        Dealer[i] = Deck[Deck_Index];
        ++Dealer_Index;
        ++Deck_Index;
    }

    for (auto Element : Dealer)
    {
        PrintCard(Element);
    }


    
    std::cout << "The player got the following cards:" << '\n';
    for (int i = 0; i < 2; ++i)
    {
        Player[Player_Index] = Deck[Deck_Index];
        ++Deck_Index;
        ++Player_Index;
    }

    for (auto Element:Player)
    {
        PrintCard(Element);
    }
    std::cout << "The player goes first: " << '\n';
    //std::cout << "You can either stand or Hit. Choose (S/H): " << '\n';
    do
    {
      std::cout << "You can either stand or Hit. Choose (S/H): " << '\n';
      std::cin >> choice;
    } while (choice!="S");

    if (choice == "S")
    {
        std::cout << "Your turn is over with a total score of: " << '\n';
        for (int i=0; i< Player_Index; ++i)
        {
            Player_Score+=getCardValue(Player[i]);
        }
        std::cout << Player_Score << '\n';
    }

    else if (choice == "H")
    {

        Player[Player_Index] = Deck[Deck_Index];
        std::cout << "You got a new card: ";
        PrintCard(Player[Player_Index]);
        for (int i = 0; i <= Player_Index; ++i)
        {
            Player_Score += getCardValue(Player[i]);
        }
        ++Player_Index;
        ++Deck_Index;
        std::cout << Player_Score << '\n';
    }
    if (Player_Score >= 21)
    {
        std::cout << " You are busted and lost:" << '\n';
    }

    else if (Player_Score < 21)
    {
        do
        {
            std::cout << " Now the dealer goes after the player:" << '\n';
            std::cout << " The dealer gets a new card and the card is:" << '\n';
            Dealer[Dealer_Index] = Deck[Deck_Index];
            PrintCard(Dealer[Dealer_Index]);
            ++Dealer_Index;
            ++Deck_Index;
            std::cout << " The total score of the dealer is:" << '\n';
            for (int i = 0; i < Dealer_Index; ++i)
            {
                Dealer_Score += getCardValue(Dealer[i]);
            }
            std::cout << Dealer_Score << '\n';

        } while (Dealer_Score < 17);

        if (Dealer_Score > 21)
        {
            std::cout << "The dealer lost" << '\n';
        }
        else if (Player_Score > Dealer_Score)
        {
            std::cout << " the player wins" << '\n';
        }
        else
        {
            std::cout << " the player loses" << '\n';
        }
    }
}



int main() 
{


    array Card_array;
    Card_array=cardDeck();
    Card_array = shuffleDeck(Card_array);
    printDeck(Card_array);
    /*Card card;
    card.m_Rank = Rank_10;
    card.m_Suits = Suits_Diamonds;*/
    playBlackjack(Card_array);
 




    return 0;
}