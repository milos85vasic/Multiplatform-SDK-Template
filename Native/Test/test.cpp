#include <string>
#include <iostream>
#include "library.h"
#include <gtest/gtest.h>

TEST(BoostLibraryTest, AvailabilityTest) {

    auto version = getBoostVersion();
    std::cout << "Boost version: " << version << std::endl;
    ASSERT_FALSE(version.empty());
}