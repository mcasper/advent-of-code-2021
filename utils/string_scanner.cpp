#include "string_scanner.h"

bool StringScanner::eof() {
    return cursor >= src.size();
}

int StringScanner::parseInt() {
    std::string temp;
    while (!eof() && isdigit(peek())) {
        temp.push_back(take());
    }
    return atoi(temp.c_str());
}

std::string StringScanner::parseCharacter(char c) {
    if (!eof() && peek() == c) {
        return std::string(1, take());
    }
    return "";
}

void StringScanner::consumeWhitespace() {
    while (!eof() && peek() == ' ') {
        take();
    }
}

char StringScanner::peek() {
    return src[cursor];
}

char StringScanner::take() {
    cursor++;
    return src[cursor - 1];
}
