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


void Deck::build() {
    for (int i = 2; i < 15; i++) {
        string x = to_string(i);
        if (i == 11) {
            x = "J";
        } 
        if (i == 12) {
            x = "Q";
        } 
        if (i == 13) {
            x = "K";
        } 
        if (i == 14) {
            x = "A";
        } 
        deck.push_back(x + 'h');
        deck.push_back(x + 's');
        deck.push_back(x + 'c');
        deck.push_back(x + 'd');
    }

    Deck::shuffleCards();
}

