#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<long, long>> tasks(n);
    for (auto i = 0; i < n; ++i) {
        std::cin >> tasks[i].second;
    }
    for (auto i = 0; i < n; ++i) {
        std::cin >> tasks[i].first;
    }
    sort(begin(tasks), end(tasks));
    auto end = -1;
    auto count = 0;
    for (const auto &task : tasks) {
        if (task.second > end) {
            ++count;
            end = task.first;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
