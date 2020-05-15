#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> lectures(n);
    for (auto &lecture : lectures) {
        std::cin >> lecture.first >> lecture.second;
    }
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
    std::cout << lectureHalls.size() << std::endl;
    return 0;
}
