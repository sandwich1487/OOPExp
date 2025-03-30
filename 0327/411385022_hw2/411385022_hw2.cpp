#include <iostream>
#include <cstdlib>

using namespace std;

int countParentheses(string input);
int countSquareBrackets(string input);
int countBraces(string input);

int main()
{
    string input;
    int parentheses;
    int squareBracket;
    int braces;

    while (true)
    {
        cout << "Input a string or 0 exit: ";
        cin >> input;
        if (input == "0") break;

        parentheses = countParentheses(input);
        squareBracket = countSquareBrackets(input);
        braces = countBraces(input);

        cout << "Parentheses: " << parentheses;
        cout << ",  Square Brackets: " << squareBracket;
        cout << ",  Braces: " << braces;
        cout << endl << endl;
    }

    return 0;
}


int countParentheses(string input)
{
    int counterL = 0;
    int counterR = 0;
    for (char c : input)
    {
        if (c == '(')
        {
            counterL++;
        }
        else if (c == ')')
        {
            if (counterL != 0)
            {
                counterL--;
            }
            else
            {
                counterR++;
            }
        }
    }

    return counterL + counterR;
}

int countSquareBrackets(string input)
{
    int counterL = 0;
    int counterR = 0;
    for (char c : input)
    {
        if (c == '[')
        {
            counterL++;
        }
        else if (c == ']')
        {
            if (counterL != 0)
            {
                counterL--;
            }
            else
            {
                counterR++;
            }
        }
    }

    return counterL + counterR;
}

int countBraces(string input)
{
    int counterL = 0;
    int counterR = 0;
    for (char c : input)
    {
        if (c == '{')
        {
            counterL++;
        }
        else if (c == '}')
        {
            if (counterL != 0)
            {
                counterL--;
            }
            else
            {
                counterR++;
            }
        }
    }

    return counterL + counterR;
}
