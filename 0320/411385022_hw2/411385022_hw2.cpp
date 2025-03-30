#include <iostream>
#include <ctime>

using namespace std;

int coinCom(int, char = 'N');

int main()
{
    int n;
    int p;
    clock_t t;

    while (true)
    {
        p = 0;
        cin >> n;
        if (n == 0) break;

        t = clock();

        p = coinCom(n, '1');

        t = clock() - t;

        cout << "Combination: " << p << endl;
        cout << "During Time: " << t << " ms" << endl << endl;
    }

    return 0;
}

int coinCom(int n, char tag)
{
    if (n < 0) return 0;
    if (n == 0) return 1;

    switch (tag)
    {
    case '1':
        return coinCom(n - 1, '1') + coinCom(n - 5, '5') + coinCom(n - 10, '0') + coinCom(n - 50);
    case '5':
        return coinCom(n - 5, '5') + coinCom(n - 10, '0') + coinCom(n - 50);
    case '0':
        return coinCom(n - 10, '0') + coinCom(n - 50);
    default:
        return coinCom(n - 50);
    }
}
