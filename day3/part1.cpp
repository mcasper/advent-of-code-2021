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

int main(int argc, char *argv[])
{
    std::vector<std::string> lines = stringListInput("../day3/part1.txt");
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
    std::cout << "most_common_bit_string " << most_common_bit_string << std::endl;

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
    std::cout << "least_common_bit_string " << least_common_bit_string << std::endl;

    int result = binaryStringToInt(most_common_bit_string) * binaryStringToInt(least_common_bit_string);
    std::cout << "Result: " << result << std::endl;
}
