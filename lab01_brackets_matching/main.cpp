#include <stack>
#include <iostream>

int getPriority(const char c) {
    switch (c) {
        case '<':
            return 1;
        case '(':
            return 2;
        case '[':
            return 3;
        case '{':
            return 4;
        case '>':
            return 5;
        case ')':
            return 6;
        case ']':
            return 7;
        case '}':
            return 8;
        default:
            return 9;
    }
}

bool judge(const std::string &str) {
    std::stack<int> stack;
    for (const auto c : str) {
        const auto priority = getPriority(c);
        if (priority < 5) {
            if (!stack.empty() && priority > stack.top()) {
                return false;
            }
            stack.push(priority);
        } else {
            if (stack.empty() || stack.top() != priority - 4) {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

int main() {
    int n;
    std::cin >> n;
    for (auto i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        if (judge(str)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
