#include "deck.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <random>
using namespace std;



Deck::Deck() {
    build();
}

// void print() {
//     for (string s : deck) {
//         cout << s << '\n';
//     }
// }

void Deck::shuffleCards() {
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}

void Deck::reset() {
    deck.clear();
    build();
}

vector<string> Deck::deal(int n) {
    vector<string> cards;
    cards.reserve(n);              
    for (int i = 0; i < n; i++) {
        cards.push_back(move(deck.back()));  
        deck.pop_back();
    }

    return cards;
}

string Deck::dealOne() {

    string card = move(deck.back());  
    deck.pop_back();

    return card;
}

int Deck::valueOf(const string& rank) {
    if (rank == "A") return 11;
    if (rank == "K" || rank == "Q" || rank == "J") return 10;
    return stoi(rank);  
}


void Deck::build() {
    static const vector<string> suits = {"h", "s", "c", "d"};

    for (int v = 2; v <= 14; v++) {
        string rank;

        if (v <= 10)       rank = to_string(v);
        else if (v == 11)  rank = "J";
        else if (v == 12)  rank = "Q";
        else if (v == 13)  rank = "K";
        else               rank = "A";  

        for (const string& s : suits) {
            deck.push_back(rank + s);   
        }
    }

    shuffleCards();
}

