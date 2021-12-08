#include <iostream>
#include <vector>

#include "../utils/io.h"

int _solve(std::string path) {
    int increased = 0;
    std::vector<int> depths = intListInput(path);
    for (int i = 2; i < depths.size() - 1; i++)
    {
        int windowASum = depths[i - 2] + depths[i - 1] + depths[i];
        int windowBSum = depths[i - 1] + depths[i] + depths[i + 1];
        if (windowBSum > windowASum)
        {
            increased++;
        }
    }

    return increased;
}

int solve() {
    return _solve("../day1/part2.txt");
}

#ifdef MY_TEST

#include <gtest/gtest.h>

TEST(Day1Part2Test, Works) {
    int expected = 5;
    int actual = _solve("../day1/sample.txt");
    EXPECT_EQ(expected, actual);
}

#endif