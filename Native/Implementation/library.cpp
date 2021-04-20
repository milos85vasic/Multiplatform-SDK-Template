#include <boost/version.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>

#include <functional>
#include <iostream>
#include <cstdlib>
#include <string>

#include "library.h"
#include "BoostInfo.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
using tcp = net::ip::tcp;

std::string getBoostVersion() {

    return std::to_string(BOOST_VERSION / 100000) + "." +
           std::to_string(BOOST_VERSION / 100 % 1000) + "." +
           std::to_string(BOOST_VERSION % 100);
}

BoostInfo getBoostInfo() {

    return BoostInfo();
}

void hello() {

    std::cout << "Using Boost " << getBoostVersion() << std::endl;
}

void tryHttpGet(const std::function<void(bool)> &callback) {

// TODO:
//    try {
//
//        auto const port = 80;
//        auto const version = "1.1";
//        auto const target = "todos/1";
//        auto const host = "jsonplaceholder.typicode.com";
//
//        net::io_context ioc;
//
//        ssl::context ctx(ssl::context::tlsv12_client);
//
//        ctx.set_verify_mode(ssl::verify_none);
//
//        tcp::resolver resolver(ioc);
////        beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);
////
////        if(! SSL_set_tlsext_host_name(stream.native_handle(), host)){
////
////            beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
////            throw beast::system_error{ec};
////        }
//
//        callback(true);
//    } catch (std::exception const &e) {
//
        callback(false);
//    }
}

void tryCallback(const std::function<void(bool)> &callback) {

    callback(true);
}