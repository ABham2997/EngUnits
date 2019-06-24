#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include "../../engunits/abstract/abstract_base.h"

namespace EngUnits{

class LengthUnit: public PhysicalUnit<> {

    protected:
        LengthUnit() : PhysicalUnit<>{} {};
        LengthUnit(const double value) : PhysicalUnit<>{value} {};
};
}

#endif