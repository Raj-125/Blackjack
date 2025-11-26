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
                    cout << "Place bet: ";
                    if (cin >> bet && bet <= player.getEarnings()) break;
                    cout << "Not enough money" << endl;
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
    int a = deck.valueOf(cards[0].substr(0,cards[0].size() - 1));
    int b = deck.valueOf(cards[1].substr(0,cards[1].size() - 1));
    int total = 0;
    if (a == 11 && b == 11) {
        total += 12;
    } 
    else if (a == 11 || b == 11) {
        int t1 = a + b;
        int t2 = a + b - 10;
        string x;
        while (true) {
            cout << "Ace = " << to_string(11) << " or " << to_string(1) + "?" << '\n';
            cin >> x;
            if (x == "11" || x == "1") {
                break;        
            }
            cout << "Invalid choice. Please enter 11 or 1." << endl;
        }
        if (x == "11") total += t1;
        else total += t2;
    }
    else {
        total += a + b;
    }
    cout << cards[0] + " / " << cards[1] << " --> Total: " + to_string(total) << endl;
    return 0;
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






