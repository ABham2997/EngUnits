#ifndef __ENGUNITS_CONVERSIONMAP_H
#define __ENGUNITS_CONVERSIONMAP_H

#include<map>
#include<string>

namespace EngUnits::conversion{

std::map<std::string, double> lengthConversionMap = {
    {"meter",1},
    {"decimeter", 10},
    {"kilometer", 1000},
    {"centimeter", 1e-2},
    {"milimeter", 1e-3},
    {"micrometer", 1e-6},
    {"nanometer", 1e-9},
    {"mile", 1609.344},
    {"yard", 0.9144},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"light year", 9.46073047258e+15},
    {"exameter", 1e+18},
    {"petameter", 1e+15}
};

}

#endif