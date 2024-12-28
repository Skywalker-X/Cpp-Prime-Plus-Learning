#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include<iostream>

class complex
{
private:
    double real;
    double imaginary;
public:
    complex();
    complex(double r, double i);
    ~complex();
    friend complex operator+(const complex & c1, const complex & c2);
    friend complex operator-(const complex & c1, const complex & c2);
    friend complex operator*(const complex & c1, const complex & c2);
    friend complex operator*(const complex & c, double n);
    friend complex operator*(double n, const complex & c);
    complex operator~() const;
    friend std::ostream & operator<<(std::ostream & os, const complex & c);
    friend std::istream & operator>>(std::istream & is, complex & c);
};

#endif