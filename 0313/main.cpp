#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Time.h"

using namespace std;

int main()
{
    Time timer;

    int num;

    string input;
    istringstream iss;
    vector<int> numbers;
    int isOkay = 0;

    while (true)
    {
        cout << "\nPlease set time: ";
        input.clear();
        getline(cin, input);
        iss.clear();
        iss.str("");
        iss.str(input);

        numbers.clear();
        while (iss >> num)
        {
            numbers.push_back(num);
        }
        
        isOkay = 0;
        if (numbers.size() == 3)
        {
            isOkay = timer.setTime(numbers[0], numbers[1], numbers[2]);
        }
        else if (numbers.size() == 1)
        {
            isOkay = timer.setTime(numbers[0]);
        }

        if (isOkay == 1)
        {
            cout << "Set time: ";
            timer.showTime();
            cout << endl;
        }
        else if (isOkay == -1)
        {
            break;
        }
        else if (isOkay == 0)
        {
            cout << "Error" << endl;
        }
    }

    return 0;
}