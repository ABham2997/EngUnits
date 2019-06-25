#ifndef __ENGUNITS_LENGTH_H
#define __ENGUNITS_LENGTH_H

#include<iostream>
#include<string>

#include "../engunits/abstract/abstract_length.h"
#include "../engunits/length_conversion_map.h"

namespace EngUnits::length{

class meters : public LengthUnit {
    public:
        using LengthUnit::LengthUnit;

        double get_conversion() const override { return conversion::lengthConversionMap["meters"]; }
        std::string get_suffix() const override { return "m"; }
};

class inches : public LengthUnit {
    public:
        using LengthUnit::LengthUnit;

        double get_conversion() const override { return conversion::lengthConversionMap["inches"]; }
        std::string get_suffix() const override { return "in"; }
};

class feet : public LengthUnit {
    public:
        using LengthUnit::LengthUnit;

        double get_conversion() const override { return conversion::lengthConversionMap["feet"]; }
        std::string get_suffix() const override { return "ft"; }
};

}

#endif