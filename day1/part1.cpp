#include <iostream>
#include <vector>

#include "../utils/io.h"

int main(int argc, char *argv[])
{
    int increased = 0;
    std::vector<int> depths = intListInput("../day1/part1.txt");
    for (int i = 0; i < depths.size() - 1; i++)
    {
        if (depths[i + 1] > depths[i])
        {
            increased++;
        }
    }

    std::cout << "Result: " << increased << std::endl;
    return 0;
}
