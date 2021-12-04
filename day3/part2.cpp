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

int main(int argc, char *argv[])
{
    std::vector<std::string> oxygenLines = stringListInput("../day3/part2.txt");
    std::vector<std::string> co2Lines = oxygenLines;
    int oxygenRating = findOxygenRating(oxygenLines);
    int co2Rating = findCo2Rating(co2Lines);

    std::cout << "Result: " << oxygenRating * co2Rating << std::endl;
}

//     for (std::string line : lines)
//     {

//         int integer = binaryStringToInt(line);
//         for (int i = 0; i < line.size(); i++)
//         {
//             int bit = (integer & (1 << i)) >> i;
//             if (bit)
//             {
//                 most_common_bits[line.size() - i - 1] += 1;
//                 least_common_bits[line.size() - i - 1] -= 1;
//             }
//             else
//             {
//                 most_common_bits[line.size() - i - 1] -= 1;
//                 least_common_bits[line.size() - i - 1] += 1;
//             }
//         }
//     }

//     std::string most_common_bit_string;
//     for (auto bit : most_common_bits)
//     {
//         assert(bit != 0);
//         if (bit < 0)
//         {
//             most_common_bit_string.append("0");
//         }
//         if (bit > 0)
//         {
//             most_common_bit_string.append("1");
//         }
//     }
//     std::cout << "most_common_bit_string " << most_common_bit_string << std::endl;

//     std::string least_common_bit_string;
//     for (auto bit : least_common_bits)
//     {
//         assert(bit != 0);
//         if (bit < 0)
//         {
//             least_common_bit_string.append("0");
//         }
//         if (bit > 0)
//         {
//             least_common_bit_string.append("1");
//         }
//     }
//     std::cout << "least_common_bit_string " << least_common_bit_string << std::endl;

//     int result = binaryStringToInt(most_common_bit_string) * binaryStringToInt(least_common_bit_string);
//     std::cout << "Result: " << result << std::endl;
// }
