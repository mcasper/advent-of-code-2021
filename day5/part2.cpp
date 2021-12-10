#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "../utils/io.h"
#include "../utils/string_scanner.h"

struct Point {
    Point(int x, int y): x(x), y(y) {}

    int x;
    int y;
};

struct Line {
    std::vector<Point> points;
};

class Graph {
public:
    void recordLine(Point startingPoint, Point endingPoint) {
        // Diagonal line
        if (startingPoint.x != endingPoint.x && startingPoint.y != endingPoint.y) {
            std::function<int(int)> xStep;
            std::function<int(int)> yStep;
            if (startingPoint.x > endingPoint.x) {
                xStep = [](int currentX) -> int { return currentX - 1; };
            } else {
                xStep = [](int currentX) -> int { return currentX + 1; };
            }

            if (startingPoint.y > endingPoint.y) {
                yStep = [](int currentY) -> int { return currentY - 1; };
            } else {
                yStep = [](int currentY) -> int { return currentY + 1; };
            }

            int x = startingPoint.x;
            int y = startingPoint.y;
            incrementPoint(y, x);
            bool done = false;
            while (!done) {
                x = xStep(x);
                y = yStep(y);
                incrementPoint(y, x);
                if (x == endingPoint.x && y == endingPoint.y) {
                    done = true;
                }
            }

            return;
        }

        // vertical line
        if (startingPoint.x == endingPoint.x) {
            int startingY = startingPoint.y > endingPoint.y ? endingPoint.y : startingPoint.y;
            int endingY = startingPoint.y > endingPoint.y ? startingPoint.y : endingPoint.y;
            int x = startingPoint.x;

            for (int y = startingY; y <= endingY; y++) {
                incrementPoint(y, x);
            }
        }

        // horizontal line
        if (startingPoint.y == endingPoint.y) {
            int startingX = startingPoint.x > endingPoint.x ? endingPoint.x : startingPoint.x;
            int endingX = startingPoint.x > endingPoint.x ? startingPoint.x : endingPoint.x;
            int y = startingPoint.y;

            for (int x = startingX; x <= endingX; x++) {
                if (coordinates.find(y) == coordinates.end()) {
                    coordinates[y] = std::map<int, int>();
                }

                if (coordinates[y].find(x) == coordinates[y].end()) {
                    coordinates[y][x] = 0;
                }

                coordinates[y][x] = coordinates[y][x]+1;
            }
        }
    }

    void incrementPoint(int y, int x) {
        if (coordinates.find(y) == coordinates.end()) {
            coordinates[y] = std::map<int, int>();
        }

        if (coordinates[y].find(x) == coordinates[y].end()) {
            coordinates[y][x] = 0;
        }

        coordinates[y][x] = coordinates[y][x]+1;
    }

    int numHighCollisionPoints() {
        int result = 0;

        for (auto const& [k, v] : coordinates) {
            for (auto const& [kk, vv] : v) {
                if (vv > 1) {
                    result++;
                }
            }
        }

        return result;
    }

private:
    std::map<int, std::map<int, int>> coordinates;
};

Point pointFromString(std::string s) {
    StringScanner scanner(s);
    int x = scanner.parseInt();
    scanner.parseCharacter(',');
    int y = scanner.parseInt();
    return Point(x, y);
}

int _solve(std::string path) {
    std::vector<std::string> inputLines = stringListInput(path);
    std::vector<Line> lines;
    Graph graph;

    for (std::string inputLine : inputLines) {
        std::vector<std::string> pointStrings = split(inputLine, " -> ");
        assert(pointStrings.size() == 2);
        Point startingPoint = pointFromString(pointStrings[0]);
        Point endingPoint = pointFromString(pointStrings[1]);
        graph.recordLine(startingPoint, endingPoint);
    }

    return graph.numHighCollisionPoints();
}

int solve() {
    return _solve("../day5/part1.txt");
}

#ifdef MY_TEST

#include <gtest/gtest.h>

TEST(Day5Part2Test, Works) {
    int expected = 12;
    int actual = _solve("../day5/sample.txt");
    EXPECT_EQ(expected, actual);
}

#endif
