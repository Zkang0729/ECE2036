/*
Author: Zixuan Kang
Date Last Modified: 2020-03-31
Organization: ECE2036 Class
Description: Complex Class Header File that defines the behaviour of the complex class.
*/

#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

namespace gtmath {
    class complex {
    public:
        complex(double real = 0, double imag = 0); // constructor with default values to 0
        void setReal(double real); // set the real part of the complex number
        void setImag(double imag); // set the imag part of the complex number
        double getReal() const; // get the real part of the complex number
        double getImag() const; // get the imag part of the complex number
        complex operator+(complex& rhs); // + operator overloading
        complex operator-(complex& rhs); // - operator overloading
        complex operator*(complex& rhs); // * operator overloading
        complex operator/(complex& rhs); // / operator overloading

    private:
        double m_real;
        double m_imag;
    };
}

std::ostream& operator<<(std::ostream& os, gtmath::complex& c); // ostream operator overloading

#endif