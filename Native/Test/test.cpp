#include "library.h"

#include <string>
#include <iostream>
#include <gtest/gtest.h>

TEST(BoostLibraryTest, AvailabilityTest) {

    auto version = getBoostVersion();
    std::cout << "The Boost library version: " << version << std::endl;
    ASSERT_FALSE(version.empty());
}

TEST(BoostIndoClassTest, VersionTest) {

    auto info = getBoostInfo();
    auto version = info.getBoostVersion();
    std::cout << "The Boost library version: " << version << std::endl;
    ASSERT_FALSE(version.empty());
}