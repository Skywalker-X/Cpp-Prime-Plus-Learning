#ifndef STONEWT_H_
#define STONEWT_H_
#include<iostream>

class Stonewt
{
public:
    enum Mode { STONE, INT_LBS, FLOAT_LBS };
private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
    Mode mode;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void set_mode(Mode form);
    friend Stonewt operator+(const Stonewt & s1, const Stonewt & s2);
    friend Stonewt operator-(const Stonewt & s1, const Stonewt & s2);
    friend Stonewt operator*(const Stonewt & s, double n);
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};
#endif