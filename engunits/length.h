#ifndef __ENGUNITS_LENGTH_H
#define __ENGUNITS_LENGTH_H

#include<iostream>
#include<string>

#include "../engunits/abstract/abstract_length.h"
#include "../engunits/length_conversion.h"

namespace EngUnits::length{

class meters : public abstract::LengthUnit<meters> {
    public:
        using abstract::LengthUnit<meters>::LengthUnit;

        static constexpr double conversion = conversion::METERS; //literal defined elsewhere for clarity

        static std::string suffix() { return "m"; }
};

class inches : public abstract::LengthUnit<inches> {
    public:
        using abstract::LengthUnit<inches>::LengthUnit;

        static constexpr double conversion = conversion::INCHES;

        static std::string suffix() { return "in"; }
};

class feet : public abstract::LengthUnit<feet> {
    public:
        using abstract::LengthUnit<feet>::LengthUnit;

        static constexpr double conversion = conversion::FEET;

        static std::string suffix() {return "ft";}
};
}

#endif