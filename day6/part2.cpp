#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../utils/io.h"
#include "../utils/string_scanner.h"

// not 742708799
// yes 1765974267455

std::map<uint64_t, uint64_t> runDay(std::map<uint64_t, uint64_t> fish) {
    std::map<uint64_t, uint64_t> newFish;
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
    std::map<uint64_t, uint64_t> fish;
    for (int i = 0; i < 9; i++) {
        fish[i] = 0;
    }
    StringScanner scanner(input);
    while (!scanner.eof()) {
        int lifespan = scanner.parseInt();
        fish[lifespan] = fish[lifespan]+1;
        scanner.parseCharacter(',');
    }

    for (int day = 0; day < 256; day++) {
        fish = runDay(fish);
    }

    uint64_t fishCount = 0;
    for (auto const& [_, v] : fish) {
        fishCount += v;
    }

    // The answer only fits in a uint64, so just print it out for now before it's downsized.
    // If more parts require a container greater than i64, we can change the `solve` return type.
    std::cout << fishCount << std::endl;
    return fishCount;
}

int solve() {
    return _solve("../day6/part1.txt");
}

#ifdef MY_TEST

#include <gtest/gtest.h>

TEST(Day6Part2Test, Works) {
    int expected = 26984457539;
    int actual = _solve("../day6/sample.txt");
    EXPECT_EQ(expected, actual);
}

#endif
