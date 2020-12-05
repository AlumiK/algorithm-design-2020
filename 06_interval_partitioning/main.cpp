#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

int intervalPartitioning(std::vector<std::pair<int, int>> &lectures) {
    sort(begin(lectures), end(lectures));
    std::priority_queue<int, std::vector<int>, std::greater<int>> lectureHalls;
    lectureHalls.push(0);
    for (const auto &lecture : lectures) {
        if (lecture.first < lectureHalls.top()) {
            lectureHalls.push(lecture.second);
        } else {
            lectureHalls.pop();
            lectureHalls.push(lecture.second);
        }
    }
    return lectureHalls.size();
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> lectures(n);
    for (auto &lecture : lectures) {
        std::cin >> lecture.first >> lecture.second;
    }
    std::cout << intervalPartitioning(lectures) << std::endl;
    return EXIT_SUCCESS;
}
