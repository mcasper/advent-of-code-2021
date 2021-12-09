#include <gtest/gtest.h>

#include "string_scanner.h"

TEST(StringScannerTests, ParsesInts) {
    int expected = 12345;
    StringScanner scanner("12345");
    int actual = scanner.parseInt();
    EXPECT_EQ(expected, actual);
}

TEST(StringScannerTests, ParsesWhitespace) {
    int expected = 12345;
    StringScanner scanner("          12345");
    scanner.consumeWhitespace();
    int actual = scanner.parseInt();
    EXPECT_EQ(expected, actual);
}

TEST(StringScannerTests, ParsesCharacters) {
    std::string expected = "|";
    StringScanner scanner("|");
    std::string actual = scanner.parseCharacter('|');
    EXPECT_EQ(expected, actual);
}
