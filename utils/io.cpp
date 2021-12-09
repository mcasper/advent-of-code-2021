#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "io.h"

std::vector<int> intListInput(std::string path)
{
    std::string content = inputFile(path);
    std::vector<int> result;

    size_t newline_index = 0;
    std::string token;
    while ((newline_index = content.find('\n')) != std::string::npos)
    {
        token = content.substr(0, newline_index);
        result.push_back(atoi(token.c_str()));
        content.erase(0, newline_index + 1);
    }

    return result;
}

std::vector<std::string> stringListInput(std::string path)
{
    std::string content = inputFile(path);
    std::vector<std::string> result;

    size_t newline_index = 0;
    std::string token;
    while ((newline_index = content.find('\n')) != std::string::npos)
    {
        token = content.substr(0, newline_index);
        result.push_back(token);
        content.erase(0, newline_index + 1);
    }

    return result;
}

std::string inputFile(std::string path)
{
    std::string content;

    std::ifstream file;
    file.open(path);

    std::string line;
    while (getline(file, line))
    {
        content.append(line);
        content.push_back('\n');
    }

    return content;
}

std::vector<std::string> split(std::string input, std::string separator)
{
    std::vector<std::string> result;

    size_t separator_index = 0;
    std::string token;
    while ((separator_index = input.find(separator)) != std::string::npos)
    {
        token = input.substr(0, separator_index);
        result.push_back(token);
        input.erase(0, separator_index + separator.size());
    }
    result.push_back(input);

    return result;
}
