#include <iostream>

using namespace std;

int main()
{
    string s1, s2;
    int start;
    int counts;


    while (true)
    {
        counts = 0;
        cin >> s1 >> s2;

        if (s1 == "0" && s2 == "0") break;
        if (s1.length() > s2.length())
        {
            cout << "false\n\n";
            continue;
        }

        start = 0;
        for (int i = 0; i < s1.length(); ++i)
        {
            for (int j = start; j < s2.length(); ++j)
            {
                if (s1[i] == s2[j])
                {
                    counts++;
                    start = j + 1;
                    break;
                }
            }
        }

        if (counts == s1.length())
        {
            cout << "true\n\n";
        }
        else
        {
            cout << "false\n\n";
        }
    }

    return 0;
}
