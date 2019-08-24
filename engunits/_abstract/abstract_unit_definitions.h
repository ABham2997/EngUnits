#ifndef __ENGUNITS_ABSTRACT_UNIT_DEFINITONS
#define __ENGUNITS_ABSTRACT_UNIT_DEFINITONS

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_abstract/macro.h"

namespace engunits::acceleration{

ADD_ABSTRACT_UNIT_TYPE(AccelerationUnit,meters_per_second_sq,ms-2);

}//namespace engunits::acceleration

namespace engunits::angle{

ADD_ABSTRACT_UNIT_TYPE(AngleUnit,radians,rad);

}//namespace engunits::angle

namespace engunits::area{

ADD_ABSTRACT_UNIT_TYPE(AreaUnit,sq_meters,m2);

}//namespace engunits::area

namespace engunits::data_storage{

ADD_ABSTRACT_UNIT_TYPE(DataStorageUnit,byte,b);

}//namespace engunits::data_storage

namespace engunits::data_transfer{

ADD_ABSTRACT_UNIT_TYPE(DataTransferUnit,megabyte_per_second,mbps);

}//namespace engunits::data_transfer

namespace engunits::distance{

ADD_ABSTRACT_UNIT_TYPE(DistanceUnit, meters, m);

}//namespace engunits::distance

namespace engunits::energy{

ADD_ABSTRACT_UNIT_TYPE(EnergyUnit,Joules,J);

}//namespace engunits::energy

namespace engunits::force{

ADD_ABSTRACT_UNIT_TYPE(ForceUnit,Newtons,N);

}//namespace engunits::force

namespace engunits::frequency{

ADD_ABSTRACT_UNIT_TYPE(FrequencyUnit,Herts,Hz);

}//namespace engunits::frequency

namespace engunits::fuel_economy{

ADD_ABSTRACT_UNIT_TYPE(FuelEconomyUnit,miles_per_gallon,mpg);

}//namespace engunits::fuel_economy

namespace engunits::mass{

ADD_ABSTRACT_UNIT_TYPE(MassUnit,kilograms,kg);

}//namespace engunits::mass

namespace engunits::pressure{

ADD_ABSTRACT_UNIT_TYPE(PressureUnit,Pascals,P);

}//namespace engunits::pressure

namespace engunits::speed{

ADD_ABSTRACT_UNIT_TYPE(SpeedUnit,meters_per_second,ms-1);

}//namespace engunits::speed

namespace engunits::temperature{

ADD_ABSTRACT_UNIT_TYPE(TemperatureUnit,Kelvin,K);

}//namespace engunits::temperature

namespace engunits::time{

ADD_ABSTRACT_UNIT_TYPE(TimeUnit,seconds,s);

}//namespace engunits::time

namespace engunits::torque{

ADD_ABSTRACT_UNIT_TYPE(TorqueUnit,Newton_meter,N.m);

}//namespace engunits::torque

namespace engunits::volume{

ADD_ABSTRACT_UNIT_TYPE(VolumeUnit,cubic_meters,m3);

}//namespace engunits::volume

namespace engunits::power{

ADD_ABSTRACT_UNIT_TYPE(PowerUnit,watt,W);

}//namespace engunits::power

#endif