#ifndef __ENGUNITS_TIME_CONVERSION_H
#define __ENGUNITS_TIME_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from seconds (how many seconds make up the unit)
constexpr double TI_SECONDS = 1;
constexpr double TI_CENTURY = 3155569580.3092456;
constexpr double TI_YEAR = 31555695.803092457;
constexpr double TI_CALENDARMONTH = 2629503.0239284774;
constexpr double TI_WEEK = 604960.6775559589;
constexpr double TI_DAY = 86430.4235090752;
constexpr double TI_HOUR = 3599.7120230381574;
constexpr double TI_MINUTE = 59.98800239952009;
constexpr double TI_PLANCKTIME = 5.390835579514825e-44;
constexpr double TI_ANOMALISTICYEAR = 31555695.803092457;
constexpr double TI_SYDERICYEAR = 31555695.803092457;
constexpr double TI_TROPICYEAR = 31555695.803092457;
constexpr double TI_DRACONTICYEAR = 29949086.552860133;
constexpr double TI_SYNODICMONTH = 2551671.3447307986;
constexpr double TI_SYDERICMONTH = 2360717.658168083;
constexpr double TI_ANOMALISTICMONTH = 2380952.380952381;
constexpr double TI_DRACONTICMONTH = 2351281.4483893723;

} // namespace engunits::conversion

#endif