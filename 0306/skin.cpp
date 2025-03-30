#include "skin.h"

Skin::Skin(string characterName, string skinName, int skinPrice)
{
    setCharacterName(characterName);
    setSkinName(skinName);
    setSkinPrice(skinPrice);
    this->isAvailible = true;
}

void Skin::setCharacterName(string characterName)
{
    this->characterName = characterName;
}

void Skin::setSkinName(string skinName)
{
    this->skinName = skinName;
}

void Skin::setSkinPrice(int skinPrice)
{
    this->skinPrice = skinPrice;
}

string Skin::getCharacterName()
{
    return this->characterName;
}

string Skin::getSkinName()
{
    return this->skinName;
}

int Skin::getSkinPrice()
{
    return this->skinPrice;
}

bool Skin::isAffordable(int balance)
{
    return balance >= this->skinPrice;
}