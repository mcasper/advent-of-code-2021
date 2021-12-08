#include <string>
#include <vector>

#include "../utils/io.h"

int _solve(std::string path) {
    int increased = 0;
    std::vector<int> depths = intListInput(path);
    for (int i = 0; i < depths.size() - 1; i++)
    {
        if (depths[i + 1] > depths[i])
        {
            increased++;
        }
    }

    return increased;
}

int solve() {
    return _solve("../day1/part1.txt");
}

#ifdef MY_TEST

#include <gtest/gtest.h>

TEST(Day1Part1Test, Works) {
    int expected = 7;
    int actual = _solve("../day1/sample.txt");
    EXPECT_EQ(expected, actual);
}

#endif