//
// Created by JEK on 4/9/2019.
//

#include "card.h"
#include <cstdlib>


using namespace std;



Card::Card(){
    myRank = 1;
    mySuit = spades;
}
Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    string cardName;
    cardName = rankString(myRank);
    cardName += suitString(mySuit);
    return cardName;
}
bool Card::sameSuitAs(const Card& c) const{
    return (this->mySuit == c.mySuit);
}
int  Card::getRank() const{
    return myRank;
}
string Card::suitString(Suit s) const{
    string suitName;
    switch(mySuit) {
        case spades:
            suitName = "s";
            break;
        case hearts:
            suitName = "h";
            break;
        case diamonds:
            suitName = "d";
            break;
        case clubs:
            suitName = "c";
            break;
    }
    return suitName;
}
string Card::rankString(int r) const{
    string cardName;
    switch(r) {
        case 1:
            cardName = "A";
            break;
        case 11:
            cardName = "J";
            break;
        case 12:
            cardName = "Q";
            break;
        case 13:
            cardName = "K";
            break;
        default: cardName = 48 + this->getRank();
    }
    return cardName;
}

bool Card::operator == (const Card& rhs) const{
    return ((myRank == rhs.myRank) && (mySuit == rhs.mySuit));
}
bool Card::operator != (const Card& rhs) const{
    return ((myRank != rhs.myRank) || (mySuit != rhs.mySuit));
}