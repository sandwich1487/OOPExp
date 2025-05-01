#include <iostream>
#include "Matrix.h"

using namespace std;

void printOptions();
void printMatrix(vector<vector<double>>& matrix);

int main()
{
    int option = 0;
    int n = 0;
    vector<vector<double>> input;
    
    cout << "Input N: ";
    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; ++i)
    {
        input[i].resize(n);
    }
    
    cout << "Input matrix A: ";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> input[i][j];
        }
    }
    Matrix A(input);

    cout << "Input matrix B: ";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> input[i][j];
        }
    }
    Matrix B(input);

    while (true)
    {
        printOptions();
        cin >> option;
        if (option == 4) break;

        if (option == 1)
        {
            vector<vector<double>> result = Matrix::add(&A, &B);
            printMatrix(result);
        }
        else if (option == 2)
        {
            vector<vector<double>> result = Matrix::sub(&A, &B);
            printMatrix(result);
        }
        else if (option == 3)
        {
            vector<vector<double>> result = Matrix::multiple(&A, &B);
            printMatrix(result);
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
    cout << "4-Exit" << endl;
}

void printMatrix(vector<vector<double>>& matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}