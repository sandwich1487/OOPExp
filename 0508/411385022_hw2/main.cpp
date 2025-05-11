#include <iostream>
#include <fstream>
#include <map>
#include <set>

#include <windows.h>

using namespace std;

int main(int argc, char** argv)
{
    SetConsoleOutputCP(65001);

    string word;
    ifstream in(argv[1]);
    ofstream out("answer.txt");
    map<string, int> counter;

    while (in >> word)
    {
        char& f = word.front();
        char& b = word.back();
        if ((f < 'A' || f > 'Z') && (f < 'a' || f > 'z'))
        {
            word.erase(word.begin());
        }
        if (word.empty()) continue;
        if ((b < 'A' || b > 'Z') && (b < 'a' || b > 'z'))
        {
            word.pop_back();
        }
        if (word.empty()) continue;

        counter[word] += 1;
    }

    for (const auto& l : counter)
    {
        cout << l.first << " 有" << l.second << "個" << '\n';
        out << l.first << " 有" << l.second << "個" << '\n';
    }

    return 0;
}