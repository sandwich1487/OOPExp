#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string word;

    while (true)
    {
        cin >> word;
        if (word == "0") break;
        reverse(word.begin(), word.end());
        cout << word << "\n\n";
    }

    return 0;
}