//
// Created by JEK on 4/9/2019.
//

#include "player.h"
#include <cstdlib>
#include <time.h>

using namespace std;

Player::Player(){
    myName = "Joseph James Williams";
}
Player::Player(string name) {
    myName = name;
}

void Player::addCard(Card c){
    myHand.push_back(c);
}
void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);                                                                       //PUT THE CARDS IN THE BOOK
    myBook.push_back(c2);
    for(int i = 0; i < myHand.size(); i++) {                                                      //ERASE THE CARDS IN THE HAND
        if((myHand[i] == c1) || (myHand[i] == c2)){
                myHand.erase(myHand.begin() + i);
                i = 0;
        }
    }
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){
    for(int i = 0; i < myHand.size(); i++){
        for(int k = i+1; k < myHand.size(); k++){
            if(myHand[i].getRank() == myHand[k].getRank()){
                c1 = myHand[i];
                c2 = myHand[k];
                return true;
            }
        }
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    int randomNum = (rand() % myHand.size());
    return(myHand[randomNum]);                            // .rankString(getRank()) WOULD GIVE THE NUMBER IN ASCII
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    for(int k = 0; k < myHand.size(); k++) {
        if(myHand[k] == c){
            return true;
        }
    }
    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    Card c1;
    for(int k = 0; k < myHand.size(); k++) {
        if (myHand[k].getRank() == c.getRank()) {
            c1 = myHand[k];
            myHand.erase (myHand.begin()+ k);
            return c1;
        }
    }
    return c1;
}

string Player::showHand() const{                        //RETURNS THE STRING OF CARDS? WHERE ARE THEY PRINTED... SAME FOR BOOK vvv
    string Hand;
    for(int k = 0; k < myHand.size(); k++) {
        Hand += myHand[k].toString();
        Hand += " ";
    }
    return Hand;
}
string Player::showBooks() const{
    string Book;
    for(int k = 0; k < myBook.size(); k++) {
        Book += myBook[k].toString();
        Book += " ";
    }
    return Book;
}

int Player::getHandSize() const{
    return (myHand.size());
}
int Player::getBookSize() const{
    return (myBook.size()/2);
}

//BELOW ARE FUNCTIONS COMPLETELY THE SAME AS CHECKHANDFORBOOK AND RANKINHAND RESPECTIVELY

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
//
//bool Player::checkHandForPair(Card &c1, Card &c2){
//
//}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

//bool Player::sameRankInHand(Card c) const{
//
//}
