# EngUnits --IN PROGRESS--
EngUnits is a C++ compile-time header-only library of engineering unit types(meters, stones, feet, kilograms etc.) and tools, with an emphasis on type safety, efficiency, readability and ease of extension and use. This library is ideal for scientific or engineering problems where consistency and type safety between unit types is required (e.g, a distance and a mass cannot be added, a volume and a velocity cannot be compared, dividing pressure by pressure does not yield pressure etc.)

To build and install the library, download the source code, then run the following commands in the base directory:
```bash
mkdir build
cd build 
cmake ..
sudo cmake --build . --config Release --target install -- -j $(nproc)
```

There is built-in support for:

- efficient comparison operator chaining
```c++
#include <engunits/engunits.h>

using namespace engunits::distance;

if (feet{10} < meters{10} < miles{10}) //...//;
```
- readable literal operators
```c++
using namespace engunits::literals;

auto unit = 250.0_ft;

std::cout << unit << '\n'; //prints "250 ft"
```

- accurate implicit conversion between unit types of the same measurement type
```c++
using namespace engunits::distance;

inches i{12};

feet f{i};

std::cout << f << '\n'; //prints "1 ft"
```

- rigorous enforcement of physical measurement rules
```c++
using namespace engunits;

auto s = make_unit<mass::stones>(10); //type-checked factory function

pressure::pascal p{10000};

p+=s //ERROR: you can't add a mass to a pressure
```

Although this library includes support for a number of different unit types, it is trivial to add your own...
```c++
namespace engunits::distance{
class MyDist: public DistanceUnit<MyDist> {
    public:
        using DistanceUnit<MyDist>::DistanceUnit;
        
        static constexpr double conversion = 12345; //conversion to si(how many meters make up this unit)
        
        std::string symbol() const override {return "MyDist";} //your unit symbol
};
} //namespace engunits::distance

namespace engunits::literals{
MyDistance operator""_MyDist(long double value) {return value;}
MyDistance operator""_MyDist(unsigned long long value) {return value;} //OPTIONAL literal operators
}//literals are kept in a separate namespace to prevent pollution of literals

``` 

Thats less than 10 lines of code! Heres how you can use your custom unit:
```c++
using namespace engunits::distance;
using namespace engunits::distance::literals;

MyDistance custom{10};

std::cout << custom << '\n'; //prints "10 MyDist"

meters m{12345};

custom = m;

std::cout << custom << '\n' //prints "1 MyDist"

auto literal = 250.0_MyDist;

std::cout << literal << '\n' //prints "250 MyDist"

```


Also included is a library of constants...
```c++
using namespace engunits;

mass::kilograms MEarth{5.9722e+24};

mass::kilograms MMoon{7.342e+22};

distance::meters R{3.844e+8};

force::Newtons FGrav = constants::G*MEarth*MMoon*(R^-2);
```

...and a library of mathematical equations...
```c++
using namespace engunits;

angle::radians r{constants::pi/2};

distance::meters m = meters{10}*maths::sin(r);

std::cout << m << '\n'; //prints "10 m"
```

For the template metaprogrammers amongst you, there is also a traits library with the following traits...
```c++
engunits::traits::is_unit
engunits::traits::is_unit_of_type
```
...these traits follow convention with the standard library and can be used, for example, in the following ways...
```c++
#include<type_traits>
#include <engunits/type_traits.h>
#include <engunits/distance.h>

using namespace engunits;
using namespace engunits::distance;

static_assert(traits::is_unit_v<feet>); //OK
static_assert(traits::is_unit_v<int>); //fails assert

feet f;
if constexpr(traits::is_unit_of_type<decltype(f),DistanceUnit>::value) {
    //...//
}

template<typename T, typename=std::enable_if_t<traits::is_unit_v<T>>
class MyUnitClass {
    //...//
};
```
