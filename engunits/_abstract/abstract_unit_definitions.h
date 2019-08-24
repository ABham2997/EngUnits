#ifndef __ENGUNITS_ABSTRACT_UNIT_DEFINITONS
#define __ENGUNITS_ABSTRACT_UNIT_DEFINITONS

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_abstract/macro.h"

namespace engunits::acceleration{

ADD_ABSTRACT_UNIT_TYPE(AccelerationUnit,meters_per_second_sq,ms-1);

}//namespace engunits::acceleration

namespace engunits::angle{

ADD_ABSTRACT_UNIT_TYPE(AngleUnit,radians,r);

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
class meters; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=meters> //TODO: constrain to children of this class
class DistanceUnit: public abstract::PhysicalUnit<DistanceUnit, Child> {
    public:
        using abstract::PhysicalUnit<DistanceUnit, Child>::PhysicalUnit;
        using si_t = meters;

        constexpr DistanceUnit<Child>(const DistanceUnit<Child> &other) : abstract::PhysicalUnit<DistanceUnit, Child>{other.val} {};
        constexpr DistanceUnit<Child>(DistanceUnit<Child> &&other) : abstract::PhysicalUnit<DistanceUnit, Child>{other.val} {};
        template <typename T>
        constexpr DistanceUnit<Child>(const DistanceUnit<T> &other) : abstract::PhysicalUnit<DistanceUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        constexpr DistanceUnit<Child>(DistanceUnit<T> &&other) : abstract::PhysicalUnit<DistanceUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(const DistanceUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(DistanceUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}  
        
};

class meters : public DistanceUnit<meters> {
    public:
        using DistanceUnit<meters>::DistanceUnit;

        static constexpr double conversion = 1;

        const std::string symbol() const override { return "m"; }
};

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