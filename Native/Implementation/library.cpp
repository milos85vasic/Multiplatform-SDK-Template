#include <boost/version.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/connect.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>

#include <string>
#include <thread>
#include <iostream>
#include <functional>

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

void executeHttpsCall(const std::function<void(bool, std::string&)> &callback) {

    try {

        auto const port = "443";
        auto const version = 11;
        auto const host = "damodred.com";
        auto const target = "favorites-march-2021-embroidery";

        net::io_context ioc;

        ssl::context ctx(ssl::context::tlsv12_client);

        ctx.set_verify_mode(ssl::verify_none);

        tcp::resolver resolver(ioc);
        beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);

        if (!SSL_set_tlsext_host_name(stream.native_handle(), host)) {

            beast::error_code ec{

                    static_cast<int>(::ERR_get_error()),
                    net::error::get_ssl_category()
            };

            throw beast::system_error{ec};
        }

        auto const results = resolver.resolve(host, port);

        beast::get_lowest_layer(stream).connect(results);

        stream.handshake(ssl::stream_base::client);

        http::request<http::string_body> req{http::verb::get, target, version};
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        http::write(stream, req);

        beast::flat_buffer buffer;

        http::response<http::dynamic_body> res;

        http::read(stream, buffer, res);

        std::cout << res << std::endl;

        beast::error_code ec;
        stream.shutdown(ec);
        if (ec == net::error::eof) {

            ec = {};
        }

        if (ec) {

            throw beast::system_error{ec};
        }

        auto body = boost::beast::buffers_to_string(res.body().data());
        callback(true, body);
    } catch (std::exception const &e) {

        std::string error(e.what());
        callback(false, error);
    }
}

void tryHttpGet(const std::function<void(bool, std::string&)> &callback) {

    std::thread thread(executeHttpsCall, callback);
    thread.join();
}

void tryCallback(const std::function<void(bool)> &callback) {

    callback(true);
}