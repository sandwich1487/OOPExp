#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main(int argc, char** argv)
{
    string name;
    string data;
    ifstream in;
    ofstream out;
    map<string, string> dict;


    in.open(argv[1]);
    out.open("output.txt");
    
    while(getline(in, data))
    {
        stringstream ss(data);
        ss >> name;
        dict[name] = data;
        ss.clear();
    }


    cin >> name;
    if (dict[name] == "")
    {
        cout << "Not Found!\n";
    }
    cout << dict[name] << '\n';
    out << dict[name] << '\n';

    return 0;
}