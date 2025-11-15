#include "blackjack.h"
#include <iostream>
using namespace std;


int main() {
    int p;
    while (true) {
            cout << " Enter Number of Players: ";
            if (cin >> p && p > 0) break;
            cout << "Invalid input! Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    Blackjack game = Blackjack(p);
    game.play();
    game.playerInfo();
    return 0;
}