#include <iostream>
#include <limits>
#include "complex.h"
#include "matrix.h"

using namespace gtmath;

int main() {

    complex c1(4.5, 6.5);
    complex c2(2.5, 6.5);
    complex c3(3.0);

    //note the output formatting on these
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;

    //doing some simple math
    complex c4 = c1 - c2;
    complex c5 = c3 - c2;
    complex c6 = c1 + c2;

    std::cout << "c4: (c1 - c2) " << c4 << std::endl;
    std::cout << "c5: (c3 - c2) " << c5 << std::endl;
    std::cout << "c6: (c1 + c2) " << c6 << std::endl;

    //m1 is a matrix with only 'integer' parts
    matrix m1(2, 2);

    m1(0,0) = 1.0;
    m1(0,1) = 2.0;
    m1(1,0) = 3.0;
    m1(1,1) = 4.0;

    //m2 is a matrix where at least one value has a 'decimal' part
    matrix m2(2, 2);

    m2(0,0) = 1.5;
    m2(0,1) = 2.0;
    m2(1,0) = 3.0;
    m2(1,1) = 4.0;

    //m3 is a matrix where at least one value has an 'imaginary' part
    matrix m3(3, 2);

    m3(0,0) = complex(1.0, 2.0);
    m3(0,1) = 1.5;
    m3(1,0) = 2.0;
    m3(1,1) = 1.0;
    m3(2,0) = 3.0;
    m3(2,1) = 4.2;

    //note the formatting on the provided output
    std::cout << "---m3---" << "\n" << m3 << "---m3---" << std::endl;

    //test the copy constructor
    matrix m4 = m3;

    std::cout << "---m4--- (m3)" << "\n" << m4 << "---m4---" << std::endl;
    std::cout << "(0,0) is m4 is " << m4(0,0) << std::endl;
    std::cout << "(0,1) in m4 is " << m4(0,1) << std::endl;
    std::cout << "(1,0) in m4 is " << m4(1,0) << std::endl;

    //test the assignment operator
    matrix m5(1, 2);
    m5 = m3;

    std::cout << "---m5--- (m3)" << "\n" << m5 << "---m5---" << std::endl;

    std::cout << "Dont forget to also check for memory leaks!" << std::endl;

    //doing some simple math
    matrix m6 = m2 + m2;
    matrix m7 = m1 - m2;

    std::cout << "---m6--- (m2 + m2)" << "\n" << m6 << "---m6---" << std::endl;
    std::cout << "---m7--- (m1 - m2)" << "\n" << m7 << "---m7---" << std::endl;
    std::cout << "m7 has " << m7.get_num_cols() << " columns and " << m7.get_num_rows() << " rows" << std::endl;

    return 0;
}