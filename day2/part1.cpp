#include <iostream>
#include <vector>

#include "../utils/io.h"

struct Instruction {
    enum Direction {
        Forward,
        Up,
        Down
    };
private:
    Direction direction;
    uint32_t magnitude;
};

int _solve(std::string path)
{
    std::vector<std::string> lines = stringListInput(path);
    uint32_t x = 0;
    int32_t y = 0;

    for (std::string line : lines) {
        Instruction::Direction direction;
        if (line.rfind("forward ", 0) != std::string::npos) {
            direction = Instruction::Direction::Forward;
        }

        if (line.rfind("up ", 0) != std::string::npos) {
            direction = Instruction::Direction::Up;
        }

        if (line.rfind("down ", 0) != std::string::npos) {
            direction = Instruction::Direction::Down;
        }

        int magnitude = atoi(line.substr(line.find(" "), line.size()).c_str());

        switch (direction) {
        case Instruction::Direction::Forward:
            x += magnitude;
            break;
        case Instruction::Direction::Up:
            y -= magnitude;
            break;
        case Instruction::Direction::Down:
            y += magnitude;
            break;
        }
    }

    return x*y;
}

int solve() {
    return _solve("../day2/part1.txt");
}

#ifdef MY_TEST

#include <gtest/gtest.h>

TEST(Day2Part1Test, Works) {
    int expected = 150;
    int actual = _solve("../day2/sample.txt");
    EXPECT_EQ(expected, actual);
}

#endif