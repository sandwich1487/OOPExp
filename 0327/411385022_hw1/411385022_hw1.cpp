#include <iostream>
#include "Matrix.h"

using namespace std;

void printOptions();

int main()
{
    int option;
    int n;
    double *input;
    
    cout << "Input N: ";
    cin >> n;
    input = new double[n * n];
    Matrix C(n);
    
    cout << "Input matrix A: ";
    for (int i = 0; i < n * n; ++i)
    {
        cin >> input[i];
    }
    Matrix A(n, input);

    cout << "Input matrix B: ";
    for (int i = 0; i < n * n; ++i)
    {
        cin >> input[i];
    }
    Matrix B(n, input);

    while (true)
    {
        printOptions();
        cin >> option;
        if (option == 5) break;

        if (option == 1)
        {
            C.add(&A, &B);
            C.printMatrix();
        }
        else if (option == 2)
        {
            C.sub(&A, &B);
            C.printMatrix();
        }
        else if (option == 3)
        {
            C.multiple(&A, &B);
            C.printMatrix();
        }
        else if (option == 4)
        {
            C.divide(&A, &B);
            C.printMatrix();
        }
    }

    return 0;
}

void printOptions()
{
    cout << endl;
    cout << "1-Addtion" << endl;
    cout << "2-Subtraction" << endl;
    cout << "3-Multiplcation" << endl;
    cout << "4-Division" << endl;
    cout << "5-Exit" << endl;
}