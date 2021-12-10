#include <string>
#include <vector>

#include "../utils/io.h"
#include "../utils/string_scanner.h"

int _solve(std::string path) {
    std::string input = stringListInput(path)[0];
    std::vector<int> positions;
    StringScanner scanner(input);

    while (!scanner.eof()) {
        positions.push_back(scanner.parseInt());
        scanner.parseCharacter(',');
    }

    int maxPosition = 0;
    int minPosition = -1;
    for (int position : positions) {
        maxPosition = std::max(maxPosition, position);

        if (minPosition == -1) {
            minPosition = position;
        } else {
            minPosition = std::min(minPosition, position);
        }
    }

    int minFuelCost = -1;
    for (int i = minPosition; i <= maxPosition; i++) {
        int fuelCost = 0;

        for (int position : positions) {
            fuelCost += std::abs(position - i);
        }

        if (minFuelCost == -1) {
            minFuelCost = fuelCost;
        } else {
            minFuelCost = std::min(minFuelCost, fuelCost);
        }
    }

    return minFuelCost;
}

int solve() {
    return _solve("../day7/input.txt");
}

#ifdef MY_TEST

#include <gtest/gtest.h>

TEST(Day7Part1Test, Works) {
    int expected = 37;
    int actual = _solve("../day7/sample.txt");
    EXPECT_EQ(expected, actual);
}

#endif
