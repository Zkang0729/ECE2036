/*
Author: Zixuan Kang
Date Last Modified: 2020-03-31
Organization: ECE2036 Class
Description: Matrix Class Header File that defines the behaviour of the matrix class.
*/

#ifndef __MATRIX__
#define __MATRIX__

#include "complex.h"

namespace gtmath
{
class matrix
{
public:
    matrix(int rows, int cols);
    matrix(matrix &copy);
    ~matrix();
    int get_num_cols();
    int get_num_rows();
    matrix &operator+(matrix &rhs);
    matrix &operator-(matrix &rhs);
    complex &operator()(int row, int col);
    matrix &operator=(matrix &rhs);

private:
    complex **m_vals;
    int rows;
    int cols;
};
} // namespace gtmath

std::ostream &operator<<(std::ostream &os, gtmath::matrix &m);

#endif