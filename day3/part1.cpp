#include <iostream>
#include <math.h>
#include <vector>

#include "../utils/io.h"

int binaryStringToInt(std::string binary_string)
{
    int result = 0;

    for (int i = 0; i < binary_string.size(); i++)
    {
        char bit_string = binary_string[binary_string.size() - i - 1];
        int bit = bit_string - '0';
        result += bit * pow(2, i);
    }
    return result;
}

int _solve(std::string path)
{
    std::vector<std::string> lines = stringListInput(path);
    std::vector<int> most_common_bits = {};
    std::vector<int> least_common_bits = {};

    for (std::string line : lines)
    {
        if (most_common_bits.empty())
        {
            for (int ii = 0; ii < line.size(); ii++)
            {
                most_common_bits.push_back(0);
            }
        }

        if (least_common_bits.empty())
        {
            for (int ii = 0; ii < line.size(); ii++)
            {
                least_common_bits.push_back(0);
            }
        }

        int integer = binaryStringToInt(line);
        for (int i = 0; i < line.size(); i++)
        {
            int bit = (integer & (1 << i)) >> i;
            if (bit)
            {
                most_common_bits[line.size() - i - 1] += 1;
                least_common_bits[line.size() - i - 1] -= 1;
            }
            else
            {
                most_common_bits[line.size() - i - 1] -= 1;
                least_common_bits[line.size() - i - 1] += 1;
            }
        }
    }

    std::string most_common_bit_string;
    for (auto bit : most_common_bits)
    {
        assert(bit != 0);
        if (bit < 0)
        {
            most_common_bit_string.append("0");
        }
        if (bit > 0)
        {
            most_common_bit_string.append("1");
        }
    }

    std::string least_common_bit_string;
    for (auto bit : least_common_bits)
    {
        assert(bit != 0);
        if (bit < 0)
        {
            least_common_bit_string.append("0");
        }
        if (bit > 0)
        {
            least_common_bit_string.append("1");
        }
    }

    return binaryStringToInt(most_common_bit_string) * binaryStringToInt(least_common_bit_string);
}

int solve() {
    return _solve("../day3/part1.txt");
}

#ifdef MY_TEST

#include <gtest/gtest.h>

TEST(Day3Part1Test, Works) {
    int expected = 198;
    int actual = _solve("../day3/sample.txt");
    EXPECT_EQ(expected, actual);
}

#endif