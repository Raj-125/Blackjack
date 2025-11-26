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

    void shuffleCards();

    void reset();

    vector<string> deal(int n);

    string dealOne();

    int valueOf(const string& rank);
    
private:
    vector<string> deck;

    void build();

};

int main();

#endif