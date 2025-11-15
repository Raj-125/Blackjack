#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "deck.h"
#include "player.h"
#include <vector>
#include <string>
#include <map>

class Blackjack {
    public:

        Blackjack(int n);

        int getPlayers();

        void playerInfo();
        
        void play();

    private:
        int numPlayers;
        vector<Player> players;
        vector<string> deck;

        void enterInfo();

        int singleRound(Player& player, Deck& deck, int bet);

};

#endif