#include"11-7complex0.h"

complex::complex()
{
    real = imaginary = 0;
}

complex::complex(double r, double i)
{
    real = r;
    imaginary = i;
}

complex::~complex()
{
}

complex operator+(const complex & c1, const complex & c2)
{
    return complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

complex operator-(const complex & c1, const complex & c2)
{
    return complex(c1.real - c2.real, c1.imaginary - c2.imaginary);
}

complex operator*(const complex & c1, const complex & c2)
{
    return complex(c1.real * c2.real - c1.imaginary * c2.imaginary, c1.real * c2.imaginary + c1.imaginary * c2.real);
}

complex operator*(const complex & c, double n)
{
    return complex(c.real * n, c.imaginary * n);
}

complex operator*(double n, const complex & c)
{
    return c * n;
}

complex complex::operator~() const
{
    return complex(real, -imaginary);
}

std::ostream & operator<<(std::ostream & os, const complex & c)
{
    os << "(" << c.real << ", " << c.imaginary << "i)";
    return os;
}

std::istream & operator>>(std::istream & is, complex & c)
{
    std::cout << "real: ";
    is >> c.real;
    if (!is)
        return is;
    std::cout << "imaginary: ";
    is >> c.imaginary;
    return is;
}