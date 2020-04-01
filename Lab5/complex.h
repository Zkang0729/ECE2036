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
        complex(double real = 0, double imag = 0);
        void setReal(double real);
        void setImag(double imag);
        double getReal() const;
        double getImag() const;
        complex operator+(complex& rhs);
        complex operator-(complex& rhs);
        complex operator*(complex& rhs);
        complex operator/(complex& rhs);

    private:
        double m_real;
        double m_imag;
    };
}

std::ostream& operator<<(std::ostream& os, gtmath::complex& c);

#endif