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
    matrix(int rows, int cols); // normal constructor
    matrix(const matrix &copy); // copy constructor
    ~matrix(); // destructor
    int get_num_cols(); // get number of columns
    int get_num_rows(); // get number of rows
    matrix operator+(matrix &rhs); // operator + overloading
    matrix operator-(matrix &rhs); // operator - overloading
    complex &operator()(int row, int col); // operator () overloading
    matrix &operator=(matrix &rhs); // assingment operator overloading

private:
    complex **m_vals; // matrix 2d array
    int rows;
    int cols;
};
} // namespace gtmath

std::ostream &operator<<(std::ostream &os, gtmath::matrix &m); // ostream operator overloading

#endif