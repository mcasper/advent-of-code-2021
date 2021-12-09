#include <gtest/gtest.h>

#include "io.h"

TEST(IOTests, SplitsStrings) {
    std::vector<std::string> expected = std::vector<std::string>({"1,1", "2,2"});
    std::string input = "1,1 -> 2,2";
    std::vector<std::string> actual = split(input, " -> ");
    EXPECT_EQ(expected, actual);
}
