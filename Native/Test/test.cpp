#include "library.h"

#include <string>
#include <thread>
#include <iostream>
#include <gtest/gtest.h>

TEST(BoostLibraryTest, AvailabilityTest) {

    auto version = getBoostVersion();
    std::cout << "The Boost library version: " << version << std::endl;
    ASSERT_FALSE(version.empty());
}

TEST(BoostInfoClassTest, VersionTest) {

    auto info = getBoostInfo();
    auto version = info.getBoostVersion();
    std::cout << "The Boost library version: " << version << std::endl;
    ASSERT_FALSE(version.empty());
}

TEST(HttpCallTest, CallbackTest) {

    auto executed = false;

    auto callback = [&executed](bool success) {

        std::cout << "Callback has been executed" << std::endl;
        executed = true;
    };

    tryCallback(callback);
    ASSERT_TRUE(executed);
}

TEST(HttpCallTest, CallTest) {

    auto result = false;
    auto executed = false;

    auto callback = [&result, &executed](bool success, std::string& responseBody) {

        std::cout << "Response: '" << responseBody << "'" << std::endl;
        result = success;
        executed = true;
    };

    tryHttpGet(callback);
    while (!executed) {

        std::this_thread::yield();
    }

    ASSERT_TRUE(executed);
    ASSERT_TRUE(result);
}