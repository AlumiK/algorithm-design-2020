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
        if (priority < 5) {  // 当当前字符为左括号时
            if (!stack.empty() && priority > stack.top()) {  // 检验优先级是否匹配
                return false;
            }
            stack.push(priority);
        } else {  // 当前字符为右括号时
            if (stack.empty() || stack.top() != priority - 4) {  // 检验左右括号是否匹配
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();  // 最后如果栈空则匹配，否则不匹配
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
