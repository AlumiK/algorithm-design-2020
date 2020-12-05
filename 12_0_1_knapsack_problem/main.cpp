#include <vector>
#include <iostream>

int knapsackProblem(const std::vector<std::pair<int, int>> &items, const int maxWeight) {
    std::vector<std::vector<int>> table(items.size() + 1, std::vector<int>(maxWeight + 1));
    for (auto i = 0; i <= items.size(); ++i) {
        for (auto w = 0; w <= maxWeight; ++w) {
            if (i == 0 || w == 0) {
                table.at(i).at(w) = 0;
            } else if (items.at(i - 1).first <= w) {
                table.at(i).at(w) = std::max(
                        items.at(i - 1).second + table.at(i - 1).at(w - items.at(i - 1).first),
                        table.at(i - 1).at(w));
            } else {
                table.at(i).at(w) = table.at(i - 1).at(w);
            }
        }
    }
    return table.at(items.size()).at(maxWeight);
}

int main() {
    int maxWeight, n;
    std::cin >> maxWeight >> n;
    std::vector<std::pair<int, int>> items(n);
    for (auto i = 0; i < n; ++i) {
        std::cin >> items.at(i).first >> items.at(i).second;
    }
    std::cout << knapsackProblem(items, maxWeight) << std::endl;
    return EXIT_SUCCESS;
}
