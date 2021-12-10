#include <string>

class StringScanner {
public:
    StringScanner(std::string src) : src(src) {}

    int parseInt();
    std::string parseCharacter(char);
    void consumeWhitespace();
    bool eof();
private:
    char peek();
    char take();

    std::string src;
    int cursor { 0 };
};
