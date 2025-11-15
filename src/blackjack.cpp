#include "blackjack.h"
#include "player.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

Blackjack::Blackjack(int n) : numPlayers(n) {}

int Blackjack::getPlayers() { return numPlayers; }

void Blackjack::playerInfo() {
    for (Player p : players) {
        cout << "Player " << to_string(p.getPlayerNo()) + ": " << p.getName() + " " << '\n'
        << "Balance = " + to_string(p.getEarnings()) << '\n' << '\n';
    }
}

void Blackjack::play() {
    enterInfo();

    while (true) {
        Deck deck;

        for (Player& player : players) {
            cout << player.getName() << '\n';
            if (player.getEarnings() > 0) {
                int bet;
                while (true) {
                    cout << "Place bet";
                    if (cin >> bet && bet <= player.getEarnings()) break;
                    cout << "Not enough money Broke nigga";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                player.setEarnings(player.getEarnings() - bet);
                int earned = singleRound(player, deck, bet);
                player.setEarnings(player.getEarnings() + earned);
            }
        }

    }

}

int Blackjack::singleRound(Player& p, Deck& deck, int bet) {
    vector<string> cards = deck.deal(2);
    
}

void Blackjack::enterInfo() {
    players.reserve(numPlayers);
    for (int i = 1; i <= getPlayers(); ++i) {
        cout << "Player " << i << " Enter Name: ";
        string name;
        cin >> name;

        int d;
        while (true) {
            cout << " Enter Deposit: ";
            if (cin >> d && d >= 10) break;
            cout << "Invalid input! Please enter an integer deposit (>= 10): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        players.emplace_back(d, i, name);
    }
}






