#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include "Stack.h"
#include "Dealer.h"

using namespace std;

int main()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    Dealer dealer;
    Stack cards;
    array<int, 52> card;
    for (int i = 0; i < 52; ++i)
    {
        card[i] = i;
    }
    shuffle (card.begin(), card.end(), default_random_engine(seed));

    int num;
    cout << "Enter a number (1 ~ 52): ";
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        cards.push(card[i]);
    }
    for (int i = num - 1; i >= 0; --i)
    {
        dealer.deal(card[i]);
    }

    int option = 0;
    while (true)
    {
        cout << endl;
        cout << "1. Deal one card" << endl;
        cout << "2. Shuffle the cards" << endl;
        cout << "3. Exit" << endl;
        cout << ": ";

        cin >> option;

        if (option == 1)
        {
            try
            {
                int cardToDeal = cards.pop();
                cout << "Dealing:" << endl;
                dealer.deal(cardToDeal);
            }
            catch(const out_of_range& oor)
            {
                cout << "There is no card" << endl;
            }
        }
        else if (option == 2)
        {
            if (cards.size() == 0)
            {
                cout << "There is no card" << endl;
            }

            vector<int> temp;
            while (cards.size() > 0)
            {
                temp.push_back(cards.pop());
            }
            shuffle(temp.begin(), temp.end(), default_random_engine(seed));
            for (int card : temp)
            {
                cards.push(card);
            }
            for (auto it = temp.rbegin(); it != temp.rend(); ++it)
            {
                dealer.deal(*it);
            }
        }
        else if (option == 3) break;
    }

    return 0;
}