#ifndef __ENGUNITS_MASS_H
#define __ENGUNITS_MASS_H

#include<iostream>
#include<string>

#include "../engunits/_abstract/abstract_mass.h"
#include "../engunits/_conversion/mass_conversion.h"

namespace engunits::mass{

class kilograms : public MassUnit<kilograms> {
    public:
        using MassUnit<kilograms>::MassUnit;

        static constexpr double conversion = conversion::M_KILOGRAMS;

        static std::string symbol() { return "kg"; }
};

class pounds : public MassUnit<pounds> {
    public:
        using MassUnit<pounds>::MassUnit;

        static constexpr double conversion = conversion::M_POUNDS;

        static std::string symbol() { return "lbf"; }
};

class ounces : public MassUnit<ounces> {
    public:
        using MassUnit<ounces>::MassUnit;

        static constexpr double conversion = conversion::M_OUNCES;

        static std::string symbol() {return "oz";}
};
}

#endif