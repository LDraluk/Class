#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
    type(type),
    position(position)
    {}
    
    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }
    
    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        
        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next,position));
        }
        if (next == ')' || next == ']' || next == '}') {
            // no opening bracket
            if (opening_brackets_stack.empty()) {
                std::cout << position+1;
                return 0;
            }
            Bracket bracket = opening_brackets_stack.top();
            if (!bracket.Matchc(next)) {
                std::cout << position+1;
                return 0;
            }
            opening_brackets_stack.pop();
        }
    }
    if (opening_brackets_stack.empty()) {
        std::cout << "Success";
        return 0;
    }
    //if stack is not empty - find first not matching
    auto bracket = opening_brackets_stack.top();
    while (!opening_brackets_stack.empty()) {
        bracket = opening_brackets_stack.top();
        opening_brackets_stack.pop();
    }
    std::cout << bracket.position+1;
    return 0;
}
