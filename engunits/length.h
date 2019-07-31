#ifndef __ENGUNITS_LENGTH_H
#define __ENGUNITS_LENGTH_H

#include<iostream>
#include<string>

#include "../engunits/_abstract/abstract_length.h"
#include "../engunits/_conversion/length_conversion.h"

namespace engunits::length{

class meters : public LengthUnit<meters> {
    public:
        using LengthUnit<meters>::LengthUnit;

        static constexpr double conversion = conversion::L_METERS;

        std::string symbol() const override { return "m"; }
};

class inches : public LengthUnit<inches> {
    public:
        using LengthUnit<inches>::LengthUnit;

        static constexpr double conversion = conversion::L_INCHES;

        std::string symbol() const override { return "in"; }
};

class feet : public LengthUnit<feet> {
    public:
        using LengthUnit<feet>::LengthUnit;

        static constexpr double conversion = conversion::L_FEET;

        std::string symbol() const override {return "ft";}
};

namespace literals{
feet operator""_ft(long double value) { return value; }
}

}

#endif