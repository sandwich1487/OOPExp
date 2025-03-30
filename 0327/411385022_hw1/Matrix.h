#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <vector>

class Matrix
{
public:
    Matrix(int);
    Matrix(int, double *);
    Matrix(std::vector<std::vector<double>>);
    
    void add(Matrix *, Matrix *);
    void sub(Matrix *, Matrix *);
    void multiple(Matrix *, Matrix *);
    void divide(Matrix *, Matrix *);
    void multipliedBy(double);
    void setToUnit();
    
    double det();
    double cofactor(int, int);
    Matrix minor(int, int);
    Matrix adjoint();

    int getDimension() const;
    double getElement(int, int) const;
    std::vector<double> getRow(int) const;
    std::vector<double> getCol(int) const;
    std::vector<std::vector<double>> getMatrix() const;
    
    bool equal(Matrix *) const;

    void printMatrix() const;
private:
    int N;
    std::vector<std::vector<double>> matrix;

    double dot(std::vector<double>, std::vector<double>);
};

#endif // MATRIX_H
