#ifndef __ENGUNITS_LENGTH_H
#define __ENGUNITS_LENGTH_H

#include<iostream>

#include "../engunits/abstract/abstract_length.h"
#include "../engunits/length_conversion_map.h"

namespace EngUnits::length{

class meters : public LengthUnit {
    public:
        meters() : LengthUnit{} {};
        meters(const double value) : LengthUnit{value} {};

        friend std::ostream &operator<<(std::ostream &os, const meters &self) { os << std::scientific<<double(self)<<"m"; return os;}
};

class feet : public LengthUnit {
    public:
        feet() : LengthUnit{} {};
        feet(const double value) : LengthUnit{value} {};

        friend std::ostream &operator<<(std::ostream &os, const feet &self) { os << std::scientific<<double(self)<<"ft"; return os;}
};

}

#endif