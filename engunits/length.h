#ifndef __ENGUNITS_LENGTH_H
#define __ENGUNITS_LENGTH_H

#include<iostream>
#include<string>

#include "../engunits/abstract/abstract_length.h"
#include "../engunits/length_conversion.h"

namespace EngUnits::length{

class meters : public LengthUnit<meters> {
    public:
        using LengthUnit<meters>::LengthUnit;

        static constexpr double conversion = conversion::METERS; //literal defined elsewhere for clarity

        static constexpr char suffix[] = "m";
};

class inches : public LengthUnit<inches> {
    public:
        using LengthUnit<inches>::LengthUnit;

        static constexpr double conversion = conversion::INCHES;

        static constexpr char suffix[] = "in";
};

class feet : public LengthUnit<feet> {
    public:
        using LengthUnit<feet>::LengthUnit;

        static constexpr double conversion = conversion::FEET;

        static constexpr char suffix[] = "ft";
};
}

#endif