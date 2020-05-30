#include <iostream>

std::string cashiersAlgorithm(int amount) {
    std::string ret;
    const int denominations[] = {50, 20, 10, 5, 1};
    for (const auto denomination : denominations) {
        const auto count = amount / denomination;
        if (count > 0) {
            ret += std::to_string(denomination) + "*" + std::to_string(count) + "+";
            amount -= denomination * count;
        }
    }
    ret.pop_back();
    return ret;
}

int main() {
    int amount;
    std::cin >> amount;
    std::cout << cashiersAlgorithm(amount) << std::endl;
    return EXIT_SUCCESS;
}
