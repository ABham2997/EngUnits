#ifndef __ENGUNITS_ABSTRACT_UNIT_H
#define __ENGUNITS_ABSTRACT_UNIT_H

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_abstract/abstract_unit_definitions.h"
#include "../../engunits/_abstract/macro.h"

#define DISTANCE typename engunits::distance::meters
#define SPEED typename engunits::speed::meters_per_second
#define AREA typename engunits::area::sq_meters
#define TIME typename engunits::time::seconds
#define PRESSURE typename engunits::pressure::Pascals
#define DATA_STORAGE typename engunits::data_storage::byte
#define ACCELERATION typename engunits::acceleration::meters_per_second_sq
#define AREA typename engunits::area::sq_meters
#define ANGLE typename engunits::angle::radians
#define VOLUME typename engunits::volume::cubic_meters
#define FUEL_ECONOMY typename engunits::fuel_economy::miles_per_gallon
#define FORCE typename engunits::force::Newtons
#define DATA_TRANSFER typename engunits::data_transfer::megabyte_per_second
#define MASS typename engunits::mass::kilograms
#define FREQUENCY typename engunits::frequency::Herts
#define TEMPERATURE typename engunits::temperature::Kelvin
#define ENERGY typename engunits::energy::Joules
#define TIME typename engunits::time::seconds
#define TORQUE typename engunits::torque::Newton_meter
#define POWER typename engunits::power::watt

ADD_TRI_OPERATORS(DISTANCE, SPEED, TIME);
ADD_TRI_OPERATORS(VOLUME, AREA, DISTANCE);
ADD_TRI_OPERATORS(FORCE, MASS, ACCELERATION);
ADD_TRI_OPERATORS(ENERGY, FORCE, DISTANCE);
ADD_TRI_OPERATORS(ENERGY, POWER, TIME);
ADD_TRI_OPERATORS(POWER, SPEED, FORCE);
ADD_TRI_OPERATORS(FORCE, PRESSURE, AREA);
ADD_TRI_OPERATORS(DATA_STORAGE, DATA_TRANSFER, TIME);
ADD_TRI_OPERATORS(SPEED, FREQUENCY, DISTANCE);

ADD_SQ_OPERATORS(DISTANCE, AREA);

ADD_RECIPROCAL_OPERATORS(FREQUENCY, TIME);

ADD_MULT_ONLY_OPERATORS(DISTANCE, ANGLE, DISTANCE);

#undef DISTANCE 
#undef SPEED 
#undef AREA 
#undef TIME 
#undef PRESSURE 
#undef DATA_STORAGE 
#undef ACCELERATION 
#undef AREA 
#undef ANGLE 
#undef VOLUME 
#undef FUEL_ECONOMY 
#undef FORCE
#undef DATA_TRANSFER 
#undef MASS 
#undef FREQUENCY 
#undef TEMPERATURE 
#undef ENERGY 
#undef TIME 


#endif