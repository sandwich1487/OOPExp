#include "Matrix.h"
#include <iostream>
#include <tgmath.h>

using namespace std;

int Matrix::n_ = 0;

Matrix::Matrix(int N)
{
    n_ = N;
    this->matrix_.resize(n_);
    for (int i = 0; i < n_; ++i)
    {
        this->matrix_[i].resize(n_, 0.0);
    }
}

Matrix::Matrix(vector<vector<double>> matrix)
{
    n_ = matrix.size();
    matrix_ = matrix;
}


vector<vector<double>> Matrix::add(Matrix *A, Matrix *B)
{
    vector<vector<double>> matrix;
    matrix.resize(n_);
    for (int i = 0; i < n_; ++i)
    {
        matrix[i].resize(n_);
        for (int j = 0; j < n_; ++j)
        {
            matrix[i][j] = A->getElement(i, j) + B->getElement(i, j);
        }
    }
    return matrix;
}

vector<vector<double>> Matrix::sub(Matrix *A, Matrix *B)
{
    vector<vector<double>> matrix;
    matrix.resize(n_);
    for (int i = 0; i < n_; ++i)
    {
        matrix[i].resize(n_);
        for (int j = 0; j < n_; ++j)
        {
            matrix[i][j] = A->getElement(i, j) - B->getElement(i, j);
        }
    }
    return matrix;
}

vector<vector<double>> Matrix::multiple(Matrix *A, Matrix *B)
{
    vector<vector<double>> matrix;
    matrix.resize(n_);
    vector<vector<double>> cols(n_);
    for (int i = 0; i < n_; ++i)
    {
        cols[i] = B->getCol(i);
    }
    
    for (int i = 0; i < n_; ++i)
    {
        matrix[i].resize(n_);
        for (int j = 0; j < n_; ++j)
        {
            matrix[i][j] = dot(A->getRow(i), cols[j]);
        }
    }
    return matrix;
}

double Matrix::getElement(int row, int col) const
{
    return matrix_[row][col];
}

vector<double> Matrix::getRow(int row) const
{
    return matrix_[row];
}

vector<double> Matrix::getCol(int col) const
{
    vector<double> column(n_);
    for (int i = 0; i < n_; ++i)
    {
        column[i] = matrix_[i][col];
    }
    return column;
}

// private

double Matrix::dot(vector<double> a, vector<double> b)
{
    double value = 0;
    for (int i = 0; i < n_; ++i)
    {
        value += a[i] * b[i];
    }
    return value;
}