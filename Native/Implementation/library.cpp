#include "library.h"
#include "BoostInfo.h"

#include <boost/version.hpp>

#include <string>
#include <iostream>

std::string getBoostVersion() {

    return std::to_string(BOOST_VERSION / 100000) + "." +
           std::to_string(BOOST_VERSION / 100 % 1000) + "." +
           std::to_string(BOOST_VERSION % 100);
}

BoostInfo getBoostInfo() {

    return BoostInfo()
}

void hello() {

    std::cout << "Using Boost " << getBoostVersion() << std::endl;
}
