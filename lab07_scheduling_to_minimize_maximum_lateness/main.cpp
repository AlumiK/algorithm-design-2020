#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> assignments(n);
    for (auto &assignment : assignments) {
        std::cin >> assignment.second >> assignment.first;
    }
    sort(begin(assignments), end(assignments));
    auto maxLateness = 0;
    auto timePassed = 0;
    for (const auto &assignment : assignments) {
        timePassed += assignment.second;
        maxLateness = std::max(maxLateness, std::max(0, timePassed - assignment.first));
    }
    std::cout << maxLateness << std::endl;
    return 0;
}
