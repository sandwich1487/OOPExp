#include "Matrix.h"
#include <iostream>
#include <tgmath.h>

using namespace std;

Matrix::Matrix(int N)
{
    this->N = N;
    this->matrix.resize(this->N);
    for (int i = 0; i < this->N; ++i)
    {
        this->matrix[i].resize(this->N, 0.0);
    }
}

Matrix::Matrix(int N, double *numbers)
{
    int iter = 0;
    this->N = N;
    this->matrix.resize(N);
    for (int i = 0; i < N; ++i)
    {
        this->matrix[i].resize(N);
        for (int j = 0; j < N; ++j)
        {
            this->matrix[i][j] = numbers[iter++];
        }
    }
}

Matrix::Matrix(vector<vector<double>> matrix)
{
    this->N = matrix.size();
    this->matrix = matrix;
}


void Matrix::add(Matrix *A, Matrix *B)
{
    int n = this->N;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            this->matrix[i][j] = A->getElement(i, j) + B->getElement(i, j);
        }
    }
}

void Matrix::sub(Matrix *A, Matrix *B)
{
    int n = this->N;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            this->matrix[i][j] = A->getElement(i, j) - B->getElement(i, j);
        }
    }
}

void Matrix::multiple(Matrix *A, Matrix *B)
{
    int n = this->N;
    vector<vector<double>> cols(n);
    for (int i = 0; i < n; ++i)
    {
        cols[i] = B->getCol(i);
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            this->matrix[i][j] = dot(A->getRow(i), cols[j]);
        }
    }
}

void Matrix::divide(Matrix *A, Matrix *B)
{
    double determinant = A->det();
    if (determinant == 0)
    {
        if (A->isTimesOf(B))
        {
            this->setToUnit();
            double multiple = B->getElement(0, 0) / A->getElement(0, 0);
            this->multipliedBy(multiple);
            return;
        }
        for (int i = 0; i < this->N; ++i)
        {
            this->matrix[i].assign(this->N,0.0);
        }
    }
    else
    {
        Matrix inverseA = A->adjoint();
        inverseA.multipliedBy(1.0 / determinant);
        this->multiple(&inverseA, B);
    }
}

void Matrix::multipliedBy(double coefficient)
{
    int n = this->N;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            this->matrix[i][j] *= coefficient;
        }
    }
}

void Matrix::setToUnit()
{
    int n = this->N;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            this->matrix[i][j] = (i == j);
        }
    }
}


double Matrix::det()
{
    if (this->getDimension() == 1) return this->getElement(0, 0);

    int n = this->getDimension();
    double value = 0;
    for (int i = 0; i < n; ++i)
    {
        value += this->getRow(0)[i] * this->cofactor(0, i);
    }
    return value;
}

double Matrix::cofactor(int row, int col)
{
    if ((row + col) % 2 == 0)
        return this->minor(row, col).det();
    return -this->minor(row, col).det();
}

Matrix Matrix::minor(int row, int col)
{
    vector<vector<double>> m = this->matrix;
    for (int i = 0; i < this->getDimension(); ++i)
    {
        m[i].erase(m[i].begin() + col);
    }
    m.erase(m.begin() + row);
    return Matrix(m); 
}

Matrix Matrix::adjoint()
{
    int iter = 0;
    int n = this->N;
    double *cofactors = new double[n * n];
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cofactors[iter++] = this->cofactor(j, i);
        }
    }
    return Matrix(n, cofactors);
}


int Matrix::getDimension() const
{
    return this->N;
}

double Matrix::getElement(int row, int col) const
{
    return this->matrix[row][col];
}

vector<double> Matrix::getRow(int row) const
{
    return this->matrix[row];
}

vector<double> Matrix::getCol(int col) const
{
    vector<double> column(this->N);
    for (int i = 0; i < this->N; ++i)
    {
        column[i] = this->matrix[i][col];
    }
    return column;
}

vector<vector<double>> Matrix::getMatrix() const
{
    return this->matrix;
}


bool Matrix::isTimesOf(Matrix *A) const
{
    int n = this->N;
    if (n != A->getDimension()) return false;

    double target;
    double ratio = A->getElement(0, 0) / this->matrix[0][0];
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
    {
        target = A->getElement(i, j) / this->matrix[i][j];
        if (target != ratio)
        {
            return false;
        }
    }

    return true;
}


void Matrix::printMatrix() const
{
    int n = this->N;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << this->matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

// private

double Matrix::dot(vector<double> a, vector<double> b)
{
    double value = 0;
    for (int i = 0; i < this->N; ++i)
    {
        value += a[i] * b[i];
    }
    return value;
}