//
// Created by JEK on 4/9/2019.
//

#include "deck.h"
#include <cstdlib>


using namespace std;


Deck::Deck(){
    for(int k = 0; k <4; k++){
        for (int i = 1; i < 14; i++) {
            myCards[myIndex] = Card(i, k);                               //FIX THIS
            myIndex++;
        }
    }
    myIndex = 0;
}

void Deck::shuffle(){
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
        cout << "deck is empty" << endl;
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
