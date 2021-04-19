#include "library.h"

#include <string>
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