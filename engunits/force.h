#ifndef __ENGUNITS_FORCE_H
#define __ENGUNITS_FORCE_H

#include<iostream>
#include<string>

#include "../engunits/_abstract/abstract_force.h"
#include "../engunits/_conversion/force_conversion.h"

namespace engunits::force{

class Newtons: public ForceUnit<Newtons> {
    public:
        using ForceUnit<Newtons>::ForceUnit;

        constexpr static double conversion = conversion::FO_NEWTONS;

        const std::string symbol() const override { return "N"; }
};

class MegaNewtons: public ForceUnit<MegaNewtons> {
    public:
        using ForceUnit<MegaNewtons>::ForceUnit;

        constexpr static double conversion = conversion::FO_MEGANEWTONS;

        const std::string symbol() const override { return "MN"; }
};

}

namespace engunits::literals{
using namespace force;

Newtons operator""_N(long double value) { return value; }
MegaNewtons operator""_MN(long double value) { return value; }

}

#endif