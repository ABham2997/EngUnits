#ifndef __ENGUNITS_MATHS_H
#define __ENGUNITS_MATHS_H

#include<cmath>

#include "../engunits/conversion/conversion_funcs.h"

namespace EngUnits{

class maths{
    public:
        template<typename S> static double cos(const S &unit) {return std::cos(conversion::double_cast(unit));}
        template<typename S> static double sin(const S &unit) {return std::sin(conversion::double_cast(unit));}
        template<typename S> static double tan(const S &unit) {return std::tan(conversion::double_cast(unit));}

};

}

#endif