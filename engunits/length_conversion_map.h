#ifndef __ENGUNITS_CONVERSIONMAP_H
#define __ENGUNITS_CONVERSIONMAP_H

#include<map>
#include<string>

namespace EngUnits::conversion{

//conversion map has been standardised to SI units: all values are conversion factors from meters
std::map<std::string, double> lengthConversionMap = {
    {"meters",1},
    {"decimeters", 10},
    {"kilometers", 1000},
    {"centimeters", 1e-2},
    {"milimeters", 1e-3},
    {"micrometers", 1e-6},
    {"nanometers", 1e-9},
    {"miles", 1609.344},
    {"yards", 0.9144},
    {"feet", 0.3048},
    {"inches", 0.0254},
    {"light years", 9.46073047258e+15},
    {"exameters", 1e+18},
    {"petameters", 1e+15}
};

}

#endif