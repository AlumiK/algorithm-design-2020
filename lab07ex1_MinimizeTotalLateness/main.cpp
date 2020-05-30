#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, std::pair<int, int>>> assignments(n);
    for (auto i = 0; i < n; ++i) {
        assignments.at(i).first = i;
        std::cin >> assignments.at(i).second.first >> assignments.at(i).second.second;
    }
    auto minLateness = std::numeric_limits<int>::max();
    do {
        auto timePassed = 0;
        auto lateness = 0;
        for (const auto &assignment : assignments) {
            timePassed += assignment.second.first;
            lateness += std::max(0, timePassed - assignment.second.second);
        }
        minLateness = std::min(minLateness, lateness);
    } while (next_permutation(begin(assignments), end(assignments)));
    std::cout << minLateness << std::endl;
    return 0;
}
