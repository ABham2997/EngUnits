#ifndef __ENGUNITS_UNDERLYING_TYPE_H
#define __ENGUNITS_UNDERLYING_TYPE_H

namespace engunits::underlying{

#ifdef ENGUNITS_UNDERLYING_TYPE
    using type = ENGUNITS_UNDERLYING_TYPE;
#else
    using type = double;
#endif

}

#endif