#ifndef __ENGUNITS_ABSTRACT_FUEL_ECONOMY_H
#define __ENGUNITS_ABSTRACT_FUEL_ECONOMY_H

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/macro.h"

namespace engunits::fuel_economy{

ADD_ABSTRACT_UNIT_TYPE(FuelEconomyUnit,miles_per_gallon,mpg);

}//namespace engunits::fuel_economy

#endif