#include "player.h"

Player::Player(int initial, int no, string n) {
    earnings = initial;
    playerNo = no;
    name = n;
}
int Player::getEarnings() const {return earnings;}
void Player::setEarnings(int val) {earnings = val;}
string Player::getName() const {return name;}
void Player::setName(string n) {name = n;}
int Player::getPlayerNo() const {return playerNo;}
void Player::setPlayerNo(int n) {playerNo = n;}

