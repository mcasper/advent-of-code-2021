#include <string>

class StringScanner {
public:
    StringScanner(std::string src) : src(src) {}

    int parseInt();
    std::string parseCharacter(char);
    void consumeWhitespace();
private:
    char peek();
    char take();
    bool eof();

    std::string src;
    int cursor { 0 };
};
