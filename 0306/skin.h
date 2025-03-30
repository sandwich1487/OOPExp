#ifndef SKIN_H
#define SKIN_H

#include <string>

using namespace std;

class Skin
{
    string characterName;
    string skinName;
    int skinPrice;
public:
    Skin(string, string, int);
    
    void setCharacterName(string);
    void setSkinName(string);
    void setSkinPrice(int);

    string getCharacterName();
    string getSkinName();
    int getSkinPrice();

    bool isAffordable(int);
    bool isAvailible;
};

#endif