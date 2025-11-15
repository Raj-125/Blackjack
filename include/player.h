#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player {
    public:
        Player(int initial, int no, string n);
        
        int getEarnings() const;
        void setEarnings(int val);

        int getPlayerNo() const;
        void setPlayerNo(int n);

        string getName() const;
        void setName(string n);
    private:
        int earnings;
        int playerNo;
        string name;
};

#endif