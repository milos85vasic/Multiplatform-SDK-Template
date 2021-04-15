#include "library.h"

#include <boost/version.hpp>

#include <iostream>

void hello() {

    std::cout << "Using Boost "
              << BOOST_VERSION / 100000 << "."
              << BOOST_VERSION / 100 % 1000 << "."
              << BOOST_VERSION % 100
              << std::endl;
}
