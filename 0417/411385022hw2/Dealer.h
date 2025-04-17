#ifndef DEALER_H
#define DEALER_H

#include <string>
#include <vector>

class Dealer
{
private:
    std::vector<std::string> cardArt_;

    static const std::string kBorder;
    static const std::vector<std::string> kPatternSpades;
    static const std::vector<std::string> kPatternHearts;
    static const std::vector<std::string> kPatternDiamonds;
    static const std::vector<std::string> kPatternClubs;

    void generateCardArt(int);
    std::string getRankString(int) const;
    const std::vector<std::string>& getSuitPattern(int) const;
public:
    Dealer() = default;

    void deal(int);
};

#endif // DEALER_H