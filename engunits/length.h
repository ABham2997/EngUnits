#ifndef __ENGUNITS_LENGTH_H
#define __ENGUNITS_LENGTH_H

#include<iostream>
#include<string>

#include "../engunits/abstract/abstract_length.h"
#include "../engunits/length_conversion.h"

namespace EngUnits::length{

struct meters : public LengthUnit {
    using LengthUnit::LengthUnit;
    meters(const double value) : LengthUnit{value, this->get_conversion()} {};

    double get_conversion() const override { return conversion::METERS; }
    std::string get_suffix() const override { return "m"; }
};

struct inches : public LengthUnit {
    using LengthUnit::LengthUnit;
    inches(const double value) : LengthUnit{value, this->get_conversion()} {};

    double get_conversion() const override { return conversion::INCHES; }
    std::string get_suffix() const override { return "in"; }
};

struct feet : public LengthUnit {
    using LengthUnit::LengthUnit;
    feet(const double value) : LengthUnit{value, this->get_conversion()} {};

    double get_conversion() const override { return conversion::FEET; }
    std::string get_suffix() const override { return "ft"; }
};

}

#endif