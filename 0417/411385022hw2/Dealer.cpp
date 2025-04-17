#include "Dealer.h"
#include <iostream>

using namespace std;


const string Dealer::kBorder = "* * * * * * * * * * *";

const vector<string> Dealer::kPatternSpades =
{
    "                   ",
    "         *         ",
    "        ***        ",
    "      *******      ",
    "    ***********    ",
    "   *************   ",
    "    ***  *  ***    ",
    "        ***        ",
    "      *******      "
};

const vector<string> Dealer::kPatternHearts =
{
    "                   ",
    "     ***   ***     ",
    "    ***** *****    ",
    "    ***********    ",
    "     *********     ",
    "      *******      ",
    "       *****       ",
    "        ***        ",
    "         *         "
};

const vector<string> Dealer::kPatternDiamonds =
{
    "         *         ",
    "        ***        ",
    "       *****       ",
    "      *******      ",
    "     *********     ",
    "      *******      ",
    "       *****       ",
    "        ***        ",
    "         *         "
};

const vector<string> Dealer::kPatternClubs =
{
    "                   ",
    "        ***        ",
    "       *****       ",
    "       *****       ",
    "    *** *** ***    ",
    "   *************   ",
    "    ***  *  ***    ",
    "        ***        ",
    "      *******      "
};

void Dealer::generateCardArt(int card)
{
    cardArt_.clear();

    string rank = getRankString(card % 13 + 1);
    string left = rank + string(19 - rank.length(), ' ');
    string right = string(19 - rank.length(), ' ') + rank;
    const vector<string>& suit = getSuitPattern(card / 13);

    cardArt_.push_back(kBorder);
    cardArt_.push_back("*" + left + "*");
    for (const string& suitLine : suit)
    {
        cardArt_.push_back("*" + suitLine + "*");
    }
    cardArt_.push_back("*" + right + "*");
    cardArt_.push_back(kBorder);
}

string Dealer::getRankString(int rank) const
{
    switch (rank)
    {
    case  1: return "A";
    case 11: return "J";
    case 12: return "Q";
    case 13: return "K";
    default: return to_string(rank);
    }
}

const vector<string>& Dealer::getSuitPattern(int suit) const
{
    switch (suit)
    {
    case 0: return kPatternSpades;
    case 1: return kPatternHearts;
    case 2: return kPatternDiamonds;
    case 3: return kPatternClubs;
    default:
        static const vector<string> kPatternEmpty;
        return kPatternEmpty;
    }
}

void Dealer::deal(int card)
{
    generateCardArt(card);

    for (const string& cardLine : cardArt_)
    {    
        cout << cardLine << endl;
    }
    cout << endl;
}