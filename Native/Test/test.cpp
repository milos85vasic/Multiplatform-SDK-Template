#include <string>
#include "library.h"
#include <gtest/gtest.h>

TEST(BoostLibraryTest, AvailabilityTest) {

    auto version = getBoostVersion();
    ASSERT_FALSE(version.empty());
}