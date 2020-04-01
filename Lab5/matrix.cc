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
  this->rows = rows;
  this->cols = cols;
  this->m_vals = new complex *[rows];
  for (int i = 0; i < rows; i++)
  {
    this->m_vals[i] = new complex[cols];
    for (int j = 0; j < cols; j++)
    {
      this->m_vals[i][j] = complex(0, 0);
    }
  }
}

matrix::matrix(matrix &copy)
{
  this->rows = copy.get_num_rows();
  this->cols = copy.get_num_cols();
  this->m_vals = new complex *[this->rows];
  for (int i = 0; i < copy.rows; i++)
  {
    this->m_vals[i] = new complex[this->cols];
    for (int j = 0; j < copy.cols; j++)
    {
      this->m_vals[i][j] = complex(copy(i, j).getReal(), copy(i, j).getImag());
    }
  }
}

matrix::~matrix()
{
  for (int i = 0; i < this->get_num_rows(); i++)
  {
    delete[] this->m_vals[i];
  }
  delete[] this->m_vals;
}

int matrix::get_num_rows() { return this->rows; }

int matrix::get_num_cols() { return this->cols; }

matrix &matrix::operator+(matrix &rhs)
{
  if (this->rows == rhs.get_num_rows() && this->cols == rhs.get_num_cols())
  {
    matrix *newMatrix = new matrix(rhs.get_num_rows(), rhs.get_num_cols());
    for (int i = 0; i < this->get_num_rows(); i++)
    {
      for (int j = 0; j < this->get_num_cols(); j++)
      {
        (*newMatrix)(i, j) = (*this)(i, j) + rhs(i, j);
      }
    }
    return *newMatrix;
  }
  else
  {
    throw "The matrix sizes do not comply.";
  }
};

matrix &matrix::operator-(matrix &rhs)
{
  if (this->rows == rhs.get_num_rows() && this->cols == rhs.get_num_cols())
  {
    matrix *newMatrix = new matrix(rhs.get_num_rows(), rhs.get_num_cols());
    for (int i = 0; i < this->get_num_rows(); i++)
    {
      for (int j = 0; j < this->get_num_cols(); j++)
      {
        (*newMatrix)(i, j) = (*this)(i, j) - rhs(i, j);
      }
    }
    return *newMatrix;
  }
  else
  {
    throw "The matrix sizes do not comply.";
  }
};

complex &matrix::operator()(int row, int col)
{
  return this->m_vals[row][col];
};

matrix &matrix::operator=(matrix &rhs)
{
  if (this != &rhs)
  {
    if (this->m_vals)
    {
      for (int i = 0; i < this->get_num_rows(); i++)
      {
        delete[](this->m_vals[i]);
      }
      delete[](this->m_vals);
    }
    this->rows = rhs.get_num_rows();
    this->cols = rhs.get_num_cols();
    this->m_vals = new complex *[this->rows];
    for (int i = 0; i < rhs.rows; i++)
    {
      this->m_vals[i] = new complex[this->cols];
      for (int j = 0; j < rhs.cols; j++)
      {
        this->m_vals[i][j] = complex(rhs(i, j).getReal(), rhs(i, j).getImag());
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
      if (j == m.get_num_cols() - 1)
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
