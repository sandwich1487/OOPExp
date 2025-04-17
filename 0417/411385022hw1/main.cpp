#include <iostream>
#include <sstream>
#include "Stack.h"

using namespace std;

int main()
{
    int num = 0;
    string input;
    Stack stk;

    cout << "Enter N numbers (1 <= N <= 10)" << endl;
    getline(cin, input);
    istringstream iss(input);
    while (iss >> num)
    {
        stk.push(num);
        if (stk.size() == 10) break;
    }

    while (true)
    {
        cout << endl;
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. empty" << endl;
        cout << "4. top" << endl;

        cin >> num;
        cout << endl;
        switch (num)
        {
        case 1:
            if (stk.size() < 10)
            {
                cout << "push number: ";
                cin >> num;
                stk.push(num);
                cout << "Stack:" << endl;
                stk.printStack();
            }
            else
            {
                cout << "The stack is full." << endl;
            }
            break;

        case 2:
            try
            {
                int p = stk.pop();
                cout << "pop number: " << p << endl;
                cout << "Stack:" << endl;
                stk.printStack();
            }
            catch (const out_of_range& oor)
            {
                cerr << oor.what() << endl;
            }
            break;

        case 3:
            stk.empty();
            cout << "Empty the stack." << endl;
            break;
        
        case 4:
            try
            {
                int t = stk.top();
                cout << "Top number is " << t << endl;
            }
            catch (const out_of_range& oor)
            {
                cerr << oor.what() << endl;
            }
            break;
            
        default:
            break;
        }
    }

    return 0;
}