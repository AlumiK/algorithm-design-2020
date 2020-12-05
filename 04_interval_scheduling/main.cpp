#include <vector>
#include <iostream>
#include <algorithm>

int intervalScheduling(std::vector<std::pair<long long int, long long int>> &tasks) {
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
    std::vector<std::pair<long long int, long long int>> tasks(n);
    for (auto &task : tasks) {
        std::cin >> task.second;
    }
    for (auto &task : tasks) {
        std::cin >> task.first;
    }
    std::cout << intervalScheduling(tasks) << std::endl;
    return EXIT_SUCCESS;
}
