/*
Author: Zixuan Kang
Date Last Modified: 2020-03-31
Organization: ECE2036 Class
Description: Complex Class Source File that overloads +, -, *, / operators and the << operators for printing.
*/

#include "complex.h"
#include <cmath>
#include <iomanip>
#include <limits>

namespace gtmath
{
complex::complex(double real, double imag)
{
  setReal(real);
  setImag(imag);
}

void complex::setReal(double real)
{
  this->m_real = real;
}

void complex::setImag(double imag)
{
  this->m_imag = imag;
}

double complex::getReal() const { return this->m_real; }

double complex::getImag() const { return this->m_imag; }

complex &complex::operator+(complex &rhs)
{
  this->m_real = this->m_real + rhs.m_real;
  this->m_imag = this->m_imag + rhs.m_imag;
  return *this;
}

complex &complex::operator-(complex &rhs)
{
  this->m_real = this->m_real - rhs.m_real;
  this->m_imag = this->m_imag - rhs.m_imag;
  return *this;
}

complex &complex::operator*(complex &rhs)
{
  this->m_real = this->m_real * rhs.m_real - this->m_imag * rhs.m_imag;
  this->m_imag = this->m_real * rhs.m_imag + this->m_imag * rhs.m_real;
  return *this;
}

complex &complex::operator/(complex &rhs)
{
  double denominator = this->m_real * this->m_real + this->m_imag * this->m_imag;
  this->m_real = (this->m_real * rhs.m_real + this->m_imag * rhs.m_imag) / denominator;
  this->m_imag = (this->m_imag * rhs.m_real - this->m_real * rhs.m_imag) / denominator;
  return *this;
}

} // namespace gtmath

std::ostream &operator<<(std::ostream &os, gtmath::complex &c)
{
  os << c.getReal() << " + " << c.getImag() << "j";
  return os;
}