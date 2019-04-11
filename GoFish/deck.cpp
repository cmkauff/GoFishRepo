//
// Created by JEK on 4/9/2019.
//

#include "deck.h"
#include <cstdlib>
#include <time.h>


using namespace std;


Deck::Deck(){
    myIndex = 0;
    for(int k = Card::spades; k <= Card::clubs; k++){
        for (int i = 1; i <= 13; i++) {
            myCards[myIndex] = Card(i, (Card::Suit) k);                               
            myIndex++;
        }
    }
    myIndex = 0;
}

void Deck::shuffle(){
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    for (int i = 0; i < 350; i++){
        Card temp = myCards[i%(SIZE)];
        int randomNum = rand()%(SIZE);
        myCards[i%(SIZE)] = myCards[randomNum];
        myCards[randomNum] = temp;
    }
    myIndex = 0;
}

Card Deck::dealCard(){
    if(myIndex == 52){
        Card c;                                                     //CHANGE THIS
        return c;
    }else {
        Card dealt;
        dealt = myCards[myIndex];
        myIndex++;
        return(dealt);
    }
}

int  Deck::size() const{
    return (SIZE - myIndex);
}
