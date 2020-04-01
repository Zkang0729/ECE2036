/*
Author: Zixuan Kang
Date Last Modified: 2020-03-31
Organization: ECE2036 Class
Description: Matrix Class Source File that overloads +, - and the << operators for printing.
It also defines the copy constructor, = operator and the destructor of the Matrix Class.
*/

#include "matrix.h"
#include <limits>

namespace gtmath
{
matrix::matrix(int rows, int cols)
{
  // set the rows and cols of the matrix
  this->rows = rows;
  this->cols = cols;
  // allocate the array on the stack
  this->m_vals = new complex *[rows];
  for (int i = 0; i < rows; i++)
  {
    this->m_vals[i] = new complex[cols];
    for (int j = 0; j < cols; j++)
    {
      //default to 0.0000 + 0.0000j
      this->m_vals[i][j] = complex(0, 0);
    }
  }
}

matrix::matrix(const matrix &copy)
{
  // set the rows and cols to the rows and cols of the copy
  this->rows = copy.rows;
  this->cols = copy.cols;
  // allocate arrays on the stack
  this->m_vals = new complex *[this->rows];
  for (int i = 0; i < copy.rows; i++)
  {
    this->m_vals[i] = new complex[this->cols];
    for (int j = 0; j < copy.cols; j++)
    {
      // get the number of each index in the copy and create another complex object in the new matrix
      this->m_vals[i][j] = complex(copy.m_vals[i][j].getReal(), copy.m_vals[i][j].getImag());
    }
  }
}

matrix::~matrix()
{
  for (int i = 0; i < this->get_num_rows(); i++)
  {
    delete[] this->m_vals[i]; // delete the cols
  }
  delete[] this->m_vals; // delete the rows
}

int matrix::get_num_rows() { return this->rows; }

int matrix::get_num_cols() { return this->cols; }

matrix matrix::operator+(matrix &rhs)
{
  if (this->rows == rhs.get_num_rows() && this->cols == rhs.get_num_cols()) // make sure that the to adders are the same size
  {
    matrix newMatrix(rhs.get_num_rows(), rhs.get_num_cols()); // create a new matrix to hold the return value
    for (int i = 0; i < this->get_num_rows(); i++)
    {
      for (int j = 0; j < this->get_num_cols(); j++)
      {
        newMatrix(i, j) = (*this)(i, j) + rhs(i, j); // adding the same index
      }
    }
    return newMatrix;
  }
  else
  {
    throw "The matrix sizes do not comply."; // throw the error when the size of the matrix does not comply to each other
  }
};

matrix matrix::operator-(matrix &rhs)
{
  if (this->rows == rhs.get_num_rows() && this->cols == rhs.get_num_cols()) // make sure that the to adders are the same size
  {
    matrix newMatrix(rhs.get_num_rows(), rhs.get_num_cols()); // create a new matrix to hold the return value
    for (int i = 0; i < this->get_num_rows(); i++)
    {
      for (int j = 0; j < this->get_num_cols(); j++)
      {
        newMatrix(i, j) = (*this)(i, j) - rhs(i, j); // subtracting the same index
      }
    }
    return newMatrix;
  }
  else
  {
    throw "The matrix sizes do not comply."; // throw the error when the size of the matrix does not comply to each other
  }
};

complex &matrix::operator()(int row, int col)
{
  return this->m_vals[row][col]; // returning the value of the corresponding index
};

matrix &matrix::operator=(matrix &rhs)
{
  if (this != &rhs) // make sure this and rhs are not the same thing
  {
    if (this->m_vals) // check if the left hand side has already a matrix inside, if yes delete them
    {
      for (int i = 0; i < this->get_num_rows(); i++)
      {
        delete[](this->m_vals[i]); // delete cols
      }
      delete[](this->m_vals); // delete rows
    }
    // allocate new rows and cols from the rhs
    this->rows = rhs.get_num_rows();
    this->cols = rhs.get_num_cols();
    // reallocate matrix on the stack
    this->m_vals = new complex *[this->rows];
    for (int i = 0; i < rhs.rows; i++)
    {
      this->m_vals[i] = new complex[this->cols];
      for (int j = 0; j < rhs.cols; j++)
      {
        this->m_vals[i][j] = complex(rhs(i, j).getReal(), rhs(i, j).getImag()); // getting the value from rhs and create new complex objects
      }
    }
  }
  return *this;
};

} // namespace gtmath

std::ostream &operator<<(std::ostream &os, gtmath::matrix &m)
{
  for (int i = 0; i < m.get_num_rows(); i++)
  {
    for (int j = 0; j < m.get_num_cols(); j++)
    {
      if (j == m.get_num_cols() - 1) // if it's the last one at the end of a row return
      {
        os << m(i, j) << std::endl;
      }
      else
      {
        os << m(i, j) << ", ";
      }
    }
  }
  return os;
}
