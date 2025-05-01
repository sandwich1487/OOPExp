#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <vector>

class Matrix
{
public:
    Matrix(int);
    Matrix(std::vector<std::vector<double>>);
    
    static std::vector<std::vector<double>> add(Matrix *, Matrix *);
    static std::vector<std::vector<double>> sub(Matrix *, Matrix *);
    static std::vector<std::vector<double>> multiple(Matrix *, Matrix *);

    double getElement(int, int) const;
    std::vector<double> getRow(int) const;
    std::vector<double> getCol(int) const;
    
private:
    static int n_;
    std::vector<std::vector<double>> matrix_;

    static double dot(std::vector<double>, std::vector<double>);
};

#endif // MATRIX_H
