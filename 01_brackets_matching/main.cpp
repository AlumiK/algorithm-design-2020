#include <stack>
#include <vector>
#include <iostream>

uint8_t getPriority(const char ch) {
    auto chars = "<([{>)]}";
    for (auto i = 0; i < 8; ++i) {
        if (chars[i] == ch) {
            return i;
        }
    }
    return 8;
}

bool isMatch(const std::string &string) {
    std::stack<uint8_t> stack;
    for (const auto ch : string) {
        const auto priority = getPriority(ch);
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

std::vector<std::string> matchBrackets(const std::vector<std::string> &strings) {
    std::vector<std::string> ret;
    ret.reserve(strings.size());
    for (const auto &string : strings) {
        ret.emplace_back(isMatch(string) ? "YES" : "NO");
    }
    return ret;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> strings(n);
    for (auto &string : strings) {
        std::cin >> string;
    }
    const auto ret = matchBrackets(strings);
    for (const auto &i : ret) {
        std::cout << i << std::endl;
    }
    return EXIT_SUCCESS;
}
