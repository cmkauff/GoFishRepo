// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 7;
    Player p1("Kate");
    Player p2("Glenn");
    Deck d;  //create a deck of cards
    d.shuffle();
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    Card c1;
    Card c2;
    Card c3;
    while(p1.checkHandForBook(c1,c2)){
        p1.bookCards(c1,c2);
    }
    while(p2.checkHandForBook(c1,c2)){
        p2.bookCards(c1,c2);
    }
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p1.getName() << " book : " << p1.showBooks() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    cout << p2.getName() << " book : " << p2.showBooks() << endl;
    if((p1.getHandSize() == 0) && (d.size() != 0)){
        c3 = d.dealCard();
        p1.addCard(c3);
    }
    if((p2.getHandSize() == 0) && (d.size() != 0)){
        c3 = d.dealCard();
        p2.addCard(c3);
    }


    while( (d.size() != 0) ){

        c1 = p1.chooseCardFromHand();
        cout << p1.getName() << " says: Do you have any " << c1.getRank() << "'s ?" << endl;
        while((p2.rankInHand(c1))){
            cout << p2.getName() << " says: I do" << endl;
            c2 = p2.removeCardFromHand(c1);
            if((p2.getHandSize() == 0) && (d.size() != 0)){
                c3 = d.dealCard();
                p2.addCard(c3);
            }
            p1.addCard(c2);
            p1.bookCards(c1, c2);
            cout << p1.getName() << " book : " << p1.showBooks() << endl;

            if((p1.getHandSize() == 0) && (d.size() != 0)){
                c3 = d.dealCard();
                p1.addCard(c3);
            }
            c1 = p1.chooseCardFromHand();
            cout << p1.getName() << " says: Do you have any " << c1.getRank() << "'s ?" << endl;
        }
        cout << p2.getName() << " says: Go Fish!" << endl;
        if((d.size() != 0)){
            c1 = d.dealCard();
            p1.addCard(c1);
            while(p1.checkHandForBook(c1,c2)){
                p1.bookCards(c1,c2);
            }
        }

        if((p1.getHandSize() == 0) && (d.size() != 0)){
            c3 = d.dealCard();
            p1.addCard(c3);
        }

        c1 = p2.chooseCardFromHand();
        cout << p2.getName() << " says: Do you have any " << c1.getRank() << "'s ?" << endl;
        while(p1.rankInHand(c1)){
            cout << p1.getName() << " says: I do" << endl;
            c2 = p1.removeCardFromHand(c1);
            if((p1.getHandSize() == 0) && (d.size() != 0)){
                c3 = d.dealCard();
                p1.addCard(c3);
            }
            p2.addCard(c2);
            p2.bookCards(c1, c2);
            cout << p2.getName() << " book : " << p2.showBooks() << endl;

            if((p2.getHandSize() == 0) && (d.size() != 0)){
                c3 = d.dealCard();
                p2.addCard(c3);
            }
            c1 = p2.chooseCardFromHand();
            cout << p2.getName() << " says: Do you have any " << c1.getRank() << "'s ?" << endl;

        }

        cout << p1.getName() << " says: Go Fish!" << endl;
        if(d.size() != 0){
            c1 = d.dealCard();
            p2.addCard(c1);
            while(p2.checkHandForBook(c1,c2)){
                p2.bookCards(c1,c2);
            }
        }
        if((p2.getHandSize() == 0) && (d.size() != 0)){
            c3 = d.dealCard();
            p2.addCard(c3);
        }

    }

    if(p1.getBookSize() > p2.getBookSize()){
        cout << p1.getName() << " WINS! Book Size: " << p1.getBookSize() << endl;
    }
    else if(p1.getBookSize() < p2.getBookSize()){
        cout << p2.getName() << " WINS! Book Size: " << p2.getBookSize() << endl;
    }
    else{
        cout << p1.getName() << " and " << p2.getName() << " TIE!" << endl;
    }
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    cout << p1.getName() << " book : " << p1.showBooks() << endl;
    cout << p2.getName() << " book : " << p2.showBooks() << endl;
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
   


