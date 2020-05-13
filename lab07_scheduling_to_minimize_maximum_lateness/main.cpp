#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> assignments(n);
    for (auto i = 0; i < n; ++i) {
        std::cin >> assignments[i].second >> assignments[i].first;
    }
    sort(begin(assignments), end(assignments));
    auto maxLateness = 0;
    auto timePassed = 0;
    for (auto &assignment : assignments) {
        timePassed += assignment.second;
        maxLateness = std::max(maxLateness, std::max(0, timePassed - assignment.first));
    }
    std::cout << maxLateness << std::endl;
    return 0;
}
