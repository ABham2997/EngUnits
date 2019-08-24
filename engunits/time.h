#ifndef __ENGUNITS_TIME_H
#define __ENGUNITS_TIME_H

#include<iostream>
#include<string>

#include "../engunits/_abstract/abstract_unit.h"
#include "../engunits/_conversion/time_conversion.h"

namespace engunits::time{

}

namespace engunits::literals{
ADD_LITERALS(time, seconds, s);
}

#endif