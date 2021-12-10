#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../utils/io.h"
#include "../utils/string_scanner.h"

std::map<int, int> runDay(std::map<int, int> fish) {
    std::map<int, int> newFish;
    for (int i = 0; i < 9; i++) {
        newFish[i] = 0;
    }

    newFish[0] = fish[1];
    newFish[1] = fish[2];
    newFish[2] = fish[3];
    newFish[3] = fish[4];
    newFish[4] = fish[5];
    newFish[5] = fish[6];
    newFish[6] = fish[7] + fish[0];
    newFish[7] = fish[8];
    newFish[8] = fish[0];

    return newFish;
}

int _solve(std::string path) {
    std::string input = stringListInput(path)[0];
    std::map<int, int> fish;
    for (int i = 0; i < 9; i++) {
        fish[i] = 0;
    }
    StringScanner scanner(input);
    while (!scanner.eof()) {
        int lifespan = scanner.parseInt();
        fish[lifespan] = fish[lifespan]+1;
        scanner.parseCharacter(',');
    }

    for (int day = 0; day < 80; day++) {
        fish = runDay(fish);
    }

    int fishCount = 0;
    for (auto const& [_, v] : fish) {
        fishCount += v;
    }

    return fishCount;
}

int solve() {
    return _solve("../day6/part1.txt");
}

#ifdef MY_TEST

#include <gtest/gtest.h>

TEST(Day6Part1Test, Works) {
    int expected = 5934;
    int actual = _solve("../day6/sample.txt");
    EXPECT_EQ(expected, actual);
}

#endif
