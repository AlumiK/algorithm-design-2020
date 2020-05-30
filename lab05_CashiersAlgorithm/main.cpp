#include <iostream>

int main() {
    int amount;
    auto first = true;
    const int denominations[] = {50, 20, 10, 5, 1};
    std::cin >> amount;
    for (const auto denomination : denominations) {
        const auto count = amount / denomination;
        if (count > 0) {
            if (!first) {
                std::cout << "+";
            }
            first = false;
            std::cout << denomination << "*" << count;
            amount -= denomination * count;
        }
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
