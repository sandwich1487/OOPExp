#include <iostream>
#include "skin.cpp"

void printList(Skin *[]);
Skin *findSkin(string, Skin *[]);

int main()
{
    int balance;
    int option;
    string character;
    string skinToBuy;
    Skin *targetSkin;
    Skin s1("C1", "S1", 100);
    Skin s2("C1", "S2", 200);
    Skin s3("C1", "S3", 300);
    Skin s4("C2", "S4", 400);
    Skin s5("C2", "S5", 700);
    Skin s6("C2", "S6", 800);
    Skin *sptr[6] = {&s1, &s2, &s3, &s4, &s5, &s6};


    cout << "Enter the account amount: ";
    cin >> balance;

    while (true)
    {
        cout << "Enter 1 to buy a skin, 2 to exit: ";
        cin >> option;
        if (option == 2) break;

        cout << endl;
        printList(sptr);
        cout << endl;
        cout << "Account balance: " << balance << endl;
        cout << endl;
        cout << "Enter the character you want to buy: ";
        cin >> character;
        cout << "Enter the skin you want to buy: ";
        cin >> skinToBuy;
        targetSkin = findSkin(skinToBuy, sptr);

        if (targetSkin->getCharacterName() != character)
        {
            cout << "That skin is not for the character.\n";
            continue;
        }

        if (!targetSkin->isAvailible)
        {
            cout << "Sold Out!" << endl;
            cout << endl;
            continue;
        }

        if (targetSkin->isAffordable(balance))
        {
            targetSkin->isAvailible = false;
            balance -= targetSkin->getSkinPrice();
            cout << endl;
            cout << "Congratulation! You have skin \"" << targetSkin->getSkinName() << "\"now.\n";
            cout << "Account Balane: " << balance << endl;
            cout << endl;
        }
        else
        {
            cout << "Sorry! Insufficient account balance.\n";
            cout << endl;
        }
    }
    cout << "\nThanks for coming. Hope to see you again soon!\n";

    return 0;
}

void printList(Skin *sptr[])
{
    cout << "================= Skin Shop =================" << endl;
    cout << endl;

    cout << sptr[0]->getCharacterName() << ":\n";
    for (int i = 0; i < 3; ++i)
    {
        if (sptr[i]->isAvailible)
        {
            cout << "  " << sptr[i]->getSkinName() << ": " << sptr[i]->getSkinPrice();
        }
        else
        {
            cout << "  " << sptr[i]->getSkinName() << ": Sold out";
        }
    }
    cout << endl;

    cout << sptr[3]->getCharacterName() << ":\n";
    for (int i = 3; i < 6; ++i)
    {
        if (sptr[i]->isAvailible)
        {
            cout << "  " << sptr[i]->getSkinName() << ": " << sptr[i]->getSkinPrice();
        }
        else
        {
            cout << "  " << sptr[i]->getSkinName() << ": Sold out";
        }
    }
    cout << endl;

    cout << endl;
    cout << "=============================================" << endl;
}

Skin *findSkin(string skinToFind, Skin *skin[])
{
    Skin *targetSkin;
    for (int i = 0; i < 6; ++i)
    {
        if (skinToFind == skin[i]->getSkinName())
        {
            targetSkin = skin[i];
        }
    }
    return targetSkin;
}