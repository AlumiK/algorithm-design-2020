#include <vector>
#include <iostream>
#include <algorithm>

int intervalScheduling(const std::vector<std::pair<long long, long long>> &tasks) {
    sort(begin(tasks), end(tasks));
    auto end = -1ll;
    auto count = 0;
    for (const auto &task : tasks) {
        if (task.second > end) {
            ++count;
            end = task.first;
        }
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<long long, long long>> tasks(n);
    for (auto &task : tasks) {
        std::cin >> task.second;
    }
    for (auto &task : tasks) {
        std::cin >> task.first;
    }
    std::cout << intervalScheduling(tasks) << std::endl;
    return EXIT_SUCCESS;
}
