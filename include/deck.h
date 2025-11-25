#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <map>
using namespace std;

class Deck {
public:
    Deck();
    
    static const map<string, int> convert;
    // void print();

    void shuffleCards();

    void reset();

    vector<string> deal(int n);

    string dealOne();
    
private:
    vector<string> deck;

    void build();

};

int main();

#endif