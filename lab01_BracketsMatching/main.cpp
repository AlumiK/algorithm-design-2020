#include <stack>
#include <iostream>

inline int getPriority(const char c) {
    auto charList = "<([{>)]}";
    for (auto i = 0; i < 8; ++i) {
        if (c == charList[i]) {
            return i;
        }
    }
    return 8;
}

inline bool judge(const std::string &str) {
    std::stack<int> stack;
    for (const auto c : str) {
        const auto priority = getPriority(c);
        if (priority < 4) {
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
