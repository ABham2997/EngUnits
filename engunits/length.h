#ifndef __ENGUNITS_LENGTH_H
#define __ENGUNITS_LENGTH_H

#include<iostream>
#include<string>

#include "../engunits/_abstract/abstract_length.h"
#include "../engunits/_conversion/length_conversion.h"

namespace EngUnits::length{

class meters : public LengthUnit<meters> {
    public:
        using LengthUnit<meters>::LengthUnit;

        static constexpr double conversion = conversion::L_METERS; //literal defined in length_conversion file for clarity

        static std::string suffix() { return "m"; }
};

class inches : public LengthUnit<inches> {
    public:
        using LengthUnit<inches>::LengthUnit;

        static constexpr double conversion = conversion::L_INCHES;

        static std::string suffix() { return "in"; }
};

class feet : public LengthUnit<feet> {
    public:
        using LengthUnit<feet>::LengthUnit;

        static constexpr double conversion = conversion::L_FEET;

        static std::string suffix() {return "ft";}
};
}

#endif