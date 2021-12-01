#include <iostream>
#include <vector>

#include "../utils/io.h"

int main(int argc, char *argv[])
{
    int increased = 0;
    std::vector<int> depths = intListInput("../day1/part2.txt");
    for (int i = 2; i < depths.size() - 1; i++)
    {
        int windowASum = depths[i - 2] + depths[i - 1] + depths[i];
        int windowBSum = depths[i - 1] + depths[i] + depths[i + 1];
        if (windowBSum > windowASum)
        {
            increased++;
        }
    }

    std::cout << "Result: " << increased << std::endl;
    return 0;
}
