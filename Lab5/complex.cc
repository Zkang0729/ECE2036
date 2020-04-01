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
  this->m_real = real;
  this->m_imag = imag;
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

complex complex::operator+(complex &rhs)
{
  double newReal = this->m_real + rhs.m_real;
  double newImag = this->m_imag + rhs.m_imag;
  return complex(newReal, newImag);
}

complex complex::operator-(complex &rhs)
{
  double newReal = this->m_real - rhs.m_real;
  double newImag = this->m_imag - rhs.m_imag;
  return complex(newReal, newImag);
}

complex complex::operator*(complex &rhs)
{
  double newReal = this->m_real * rhs.m_real - this->m_imag * rhs.m_imag;
  double newImag = this->m_real * rhs.m_imag + this->m_imag * rhs.m_real;
  return complex(newReal, newImag);
}

complex complex::operator/(complex &rhs)
{
  double denominator = this->m_real * this->m_real + this->m_imag * this->m_imag;
  double newReal = (this->m_real * rhs.m_real + this->m_imag * rhs.m_imag) / denominator;
  double newImag = (this->m_imag * rhs.m_real - this->m_real * rhs.m_imag) / denominator;
  return complex(newReal, newImag);
}

} // namespace gtmath

std::ostream &operator<<(std::ostream &os, gtmath::complex &c)
{
  os << std::fixed << std::setprecision(4) << c.getReal() << (c.getImag() >= 0 ? " + " : " - ") << std::setprecision(4) << (c.getImag() < 0 ? -1 * c.getImag() : c.getImag()) << "j";
  return os;
}