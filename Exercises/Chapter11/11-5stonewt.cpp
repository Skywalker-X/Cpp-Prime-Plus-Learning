#include<iostream>
using std::cout;
#include"11-5stonewt.h"

Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{
}

void Stonewt::set_mode(Mode form)
{
    mode = form;
}

Stonewt operator+(const Stonewt & s1, const Stonewt & s2)
{
    return Stonewt(s1.pounds + s2.pounds);
}

Stonewt operator-(const Stonewt & s1, const Stonewt & s2)
{
    return Stonewt(s1.pounds - s2.pounds);
}

Stonewt operator*(const Stonewt & s, double n)
{
    return Stonewt(s.pounds * n);
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
    if (s.mode == Stonewt::STONE)
        os << s.stone << " stone, " << s.pds_left << " pounds";
    else if (s.mode == Stonewt::INT_LBS)
        os << int(s.pounds) << " pounds";
    else if (s.mode == Stonewt::FLOAT_LBS)
        os << s.pounds << " pounds";
    return os;
}