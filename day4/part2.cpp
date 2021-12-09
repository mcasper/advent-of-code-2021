#include <string>
#include <vector>
#include <iostream>

#include "../utils/io.h"

class StringScanner {
public:
    StringScanner(std::string src) : src(src) {}

    bool eof() {
        return cursor >= src.size();
    }

    int parseInt() {
        std::string temp;
        while (!eof() && isdigit(peek())) {
            temp.push_back(take());
        }
        return atoi(temp.c_str());
    }

    void consumeWhitespace() {
        while (!eof() && peek() == ' ') {
            take();
        }
    }

    char peek() {
        return src[cursor];
    }

    char take() {
        cursor++;
        return src[cursor - 1];
    }
private:
    std::string src;
    int cursor { 0 };
};

class BingoBoard {
public:
    void apply(int number) {
        for (int rowIndex = 0; rowIndex < rows.size(); rowIndex++) {
            for (int numIndex = 0; numIndex < rows[rowIndex].size(); numIndex++) {
                if (rows[rowIndex][numIndex] == number) {
                    rowBitMaps[rowIndex] |= 1 << numIndex;
                    if (rowBitMaps[rowIndex] == 31) { // 11111 in decimal
                        won_ = true;
                    }

                    columnBitMaps[numIndex] |= 1 << rowIndex;
                    if (columnBitMaps[numIndex] == 31) { // 11111 in decimal
                        won_ = true;
                    }
                }
            }
        }
    }

    int uncalled_sum() {
        int sum = 0;

        for (int rowIndex = 0; rowIndex < rows.size(); rowIndex++) {
            for (int numIndex = 0; numIndex < rows[rowIndex].size(); numIndex++) {
                int bit = (rowBitMaps[rowIndex] & (1 << numIndex)) >> numIndex;
                if (!bit) {
                    sum += rows[rowIndex][numIndex];
                }
            }
        }

        return sum;
    }

    void print() {
        for (std::vector<int> row : rows) {
            for (int num : row) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    bool won() const { return won_; }

    std::vector<std::vector<int>> rows;
    std::vector<int> rowBitMaps { std::vector<int>(5) };
    std::vector<int> columnBitMaps { std::vector<int>(5) };
private:
    bool won_ { false };
};

std::vector<BingoBoard> parseBoards(std::vector<std::string> lines) {
    std::vector<BingoBoard> result;
    int lineIndex = 0;

    BingoBoard boardInProgress;
    while (lineIndex < lines.size()) {
        std::string line = lines[lineIndex];
        if (line.empty()) {
            if (!boardInProgress.rows.empty()) {
                result.push_back(boardInProgress);
                boardInProgress = BingoBoard();
            }
            lineIndex++;
            continue;
        }

        std::vector<int> row;
        StringScanner scanner(line);
        scanner.consumeWhitespace();
        row.push_back(scanner.parseInt());
        scanner.consumeWhitespace();
        row.push_back(scanner.parseInt());
        scanner.consumeWhitespace();
        row.push_back(scanner.parseInt());
        scanner.consumeWhitespace();
        row.push_back(scanner.parseInt());
        scanner.consumeWhitespace();
        row.push_back(scanner.parseInt());
        boardInProgress.rows.push_back(row);

        lineIndex++;
    }
    if (!boardInProgress.rows.empty()) {
        result.push_back(boardInProgress);
    }

    return result;
}

std::vector<int> parseNumbers(std::string line) {
    std::vector<int> result;
    for (std::string el : split(line, ",")) {
        result.push_back(atoi(el.c_str()));
    }
    return result;
}

int _solve(std::string path) {
    std::vector<std::string> lines = stringListInput(path);
    assert(lines.size() > 1);
    std::vector<int> called_numbers = parseNumbers(lines[0]);
    std::vector<BingoBoard> boards = parseBoards(std::vector<std::string>(lines.begin()+1, lines.end()));

    int wonBoards = 0;
    for (int number : called_numbers) {
        for (int boardIndex = 0; boardIndex < boards.size(); boardIndex++) {
            if (!boards[boardIndex].won()) {
                boards[boardIndex].apply(number);

                if (boards[boardIndex].won()) {
                    if (boards.size() - wonBoards == 1) {
                        return boards[boardIndex].uncalled_sum() * number;
                    } else {
                        wonBoards++;
                    }
                }
            }
        }
    }

    assert(false);
    return 0;
}

int solve() {
    return _solve("../day4/part2.txt");
}

#ifdef MY_TEST

#include <gtest/gtest.h>

TEST(Day4Part1Test, Works) {
    int expected = 1924;
    int actual = _solve("../day4/sample.txt");
    EXPECT_EQ(expected, actual);
}

TEST(StringScanner, ParsesInts) {
    int expected = 12345;
    StringScanner scanner("12345");
    int actual = scanner.parseInt();
    EXPECT_EQ(expected, actual);
}

TEST(StringScanner, ParsesWhitespace) {
    int expected = 12345;
    StringScanner scanner("          12345");
    scanner.consumeWhitespace();
    int actual = scanner.parseInt();
    EXPECT_EQ(expected, actual);
}

#endif
