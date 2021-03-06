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

int findOxygenRating(std::vector<std::string> lines)
{
    for (int bitIndex = 0; bitIndex < lines[0].size(); bitIndex++)
    {
        if (lines.size() == 1)
        {
            return binaryStringToInt(lines[0]);
        }

        int most_common_bit = 0;
        std::vector<std::string> zero_lines;
        std::vector<std::string> one_lines;
        for (auto line : lines)
        {
            int integer = binaryStringToInt(line);
            int little_endian_pos = lines[0].size() - 1 - bitIndex;
            int bit = (integer & (1 << little_endian_pos)) >> little_endian_pos;
            if (bit)
            {
                most_common_bit++;
                one_lines.push_back(line);
            }
            else
            {
                most_common_bit--;
                zero_lines.push_back(line);
            }
        }

        if (most_common_bit >= 0)
        {
            lines = one_lines;
        }
        else
        {
            lines = zero_lines;
        }
    }

    assert(lines.size() == 1);
    return binaryStringToInt(lines[0]);
}

int findCo2Rating(std::vector<std::string> lines)
{
    for (int bitIndex = 0; bitIndex < lines[0].size(); bitIndex++)
    {
        if (lines.size() == 1)
        {
            return binaryStringToInt(lines[0]);
        }

        int most_common_bit = 0;
        std::vector<std::string> zero_lines;
        std::vector<std::string> one_lines;
        for (auto line : lines)
        {
            int integer = binaryStringToInt(line);
            int little_endian_pos = lines[0].size() - 1 - bitIndex;
            int bit = (integer & (1 << little_endian_pos)) >> little_endian_pos;
            if (bit)
            {
                most_common_bit++;
                one_lines.push_back(line);
            }
            else
            {
                most_common_bit--;
                zero_lines.push_back(line);
            }
        }

        if (most_common_bit >= 0)
        {
            lines = zero_lines;
        }
        else
        {
            lines = one_lines;
        }
    }

    assert(lines.size() == 1);
    return binaryStringToInt(lines[0]);
}

int _solve(std::string path)
{
    std::vector<std::string> oxygenLines = stringListInput(path);
    std::vector<std::string> co2Lines = oxygenLines;
    int oxygenRating = findOxygenRating(oxygenLines);
    int co2Rating = findCo2Rating(co2Lines);

    return oxygenRating * co2Rating;
}

int solve() {
    return _solve("../day3/part2.txt");
}

#ifdef MY_TEST

#include <gtest/gtest.h>

TEST(Day3Part2Test, Works) {
    int expected = 230;
    int actual = _solve("../day3/sample.txt");
    EXPECT_EQ(expected, actual);
}

#endif
