#include "BoostInfo.h"

#include <string>
#include <boost/version.hpp>

BoostInfo::BoostInfo() {

    version = std::to_string(BOOST_VERSION / 100000) + "." +
                    std::to_string(BOOST_VERSION / 100 % 1000) + "." +
                    std::to_string(BOOST_VERSION % 100);
}

std::string BoostInfo::getBoostVersion() {

    return version;
}