#ifndef Math_Expression_h
#define Math_Expression_h

#include <queue>
#include <string>
using std::string;
using std::queue;

typedef std::string Symbol;

class Expression : public queue<Symbol> {
protected:
    enum char_category_type {
        alphabetic = 0,
        numeric = 1,
        special = 2,
        whitespace = 3
    };
    char_category_type char_category(const char& c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            return alphabetic;
        if ((c >= '0' && c <= '9') || c == '.')
            return numeric;
        if (c == ' ')
            return whitespace;
        return special;
    }
public:
    virtual void parse(string) {}
};

class Postfix : public Expression {
public:
    void parse(string str) {
        size_t symbol_start = 0;
        char_category_type symbol_category;
        while (true) {
            Symbol symbol;
            for (size_t i = symbol_start; i < str.size(); i++) {
                if (i == symbol_start) {
                    if (char_category(str[i]) == whitespace) {
                        symbol_start++;
                        continue;
                    }
                    symbol_category = char_category(str[i]);
                    symbol.push_back(str[i]);
                } else {
                    if (symbol_category != char_category(str[i]))
                        break;
                }
            }
            if (!symbol.size()) break;
            symbol_start += symbol.size();
            push(std::move(symbol));
        }
    }
};

#endif
