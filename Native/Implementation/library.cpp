#include <string>
#include <iostream>
#include <functional>
#include <boost/version.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

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

void tryHttpGet(const std::function<void(bool)> &callback) {

    // TODO: Execute boost http get
    callback(false);
}

void tryCallback(const std::function<void(bool)> &callback) {

    callback(false);
}