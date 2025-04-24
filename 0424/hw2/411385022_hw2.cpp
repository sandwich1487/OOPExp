#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string name = "A";
    vector<string> vincent;
    vector<string> leo;
    vector<string> invitee;

    cout << "#Vincent's friend:" << endl;
    cin >> name;
    while (name != "0")
    {
        vincent.push_back(name);
        cin >> name;
    }
    cout << endl;

    cout << "#Leo's friend:" << endl;
    cin >> name;
    while (name != "0")
    {
        leo.push_back(name);
        cin >> name;
    }
    cout << endl;

    invitee = vincent;
    for (const string& name : leo)
    {
        if (find(vincent.begin(), vincent.end(), name) == vincent.end())
        {
            invitee.push_back(name);
        }
    }

    cout << "#Invitee:" << endl;
    for (const string& name : invitee)
    {
        cout << name << endl;
    }
    cout << endl;

    return 0;
}