#include <string>
#include <iostream>
#include <boost/version.hpp>

#include "library.h"
#include "BoostInfo.h"

std::string getBoostVersion() {

    return std::to_string(BOOST_VERSION / 100000) + "." +
           std::to_string(BOOST_VERSION / 100 % 1000) + "." +
           std::to_string(BOOST_VERSION % 100);
}

BoostInfo getBoostInfo() {

    auto info = BoostInfo();
    return info;
}

void hello() {

    std::cout << "Using Boost " << getBoostVersion() << std::endl;
}
