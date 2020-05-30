#include <vector>
#include <iostream>
#include <algorithm>

int minimizeMaximumLateness(const std::vector<std::pair<int, int>> &assignments) {
    sort(begin(assignments), end(assignments));
    auto maxLateness = 0;
    auto timePassed = 0;
    for (const auto &assignment : assignments) {
        timePassed += assignment.second;
        maxLateness = std::max(maxLateness, std::max(0, timePassed - assignment.first));
    }
    return maxLateness;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> assignments(n);
    for (auto &assignment : assignments) {
        std::cin >> assignment.second >> assignment.first;
    }
    std::cout << minimizeMaximumLateness(assignments) << std::endl;
    return EXIT_SUCCESS;
}
