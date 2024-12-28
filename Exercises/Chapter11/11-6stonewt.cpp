#include "11-6stonewt.h"
#include <iostream>

Stonewt::Stonewt(double lbs) : pounds(lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = lbs - stone * Lbs_per_stn;
}

Stonewt::Stonewt(int stn, double lbs) : stone(stn), pds_left(lbs)
{
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt() : stone(0), pds_left(0.0), pounds(0.0) {}

Stonewt::~Stonewt() {}

bool Stonewt::operator<(const Stonewt & s) const
{
    return pounds < s.pounds;
}

bool Stonewt::operator<=(const Stonewt & s) const
{
    return pounds <= s.pounds;
}

bool Stonewt::operator>(const Stonewt & s) const
{
    return pounds > s.pounds;
}

bool Stonewt::operator>=(const Stonewt & s) const
{
    return pounds >= s.pounds;
}

bool Stonewt::operator==(const Stonewt & s) const
{
    return pounds == s.pounds;
}

bool Stonewt::operator!=(const Stonewt & s) const
{
    return pounds != s.pounds;
}

void Stonewt::show_lbs() const
{
    std::cout << pounds << " pounds\n";
}

void Stonewt::show_stn() const
{
    std::cout << stone << " stone, " << pds_left << " pounds\n";
}