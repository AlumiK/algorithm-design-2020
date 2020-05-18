#include <vector>
#include <iostream>
#include <algorithm>

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
    sort(begin(tasks), end(tasks));
    auto end = -1;
    auto count = 0ll;
    for (const auto &task : tasks) {
        if (task.second > end) {
            ++count;
            end = task.first;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
