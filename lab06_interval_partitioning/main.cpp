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
    std::priority_queue<int, std::vector<int>, std::greater<int>> lectureHalls;  // 记录教室的使用结束时间，最小级优先
    lectureHalls.push(0);  // 初始化一个教室
    for (const auto &lecture : lectures) {
        // 如果讲座的开始时间早于教室的最早使用结束时间，开辟一个新教室
        if (lecture.first < lectureHalls.top()) {
            lectureHalls.push(lecture.second);  // 将新教室的使用结束时间保存
        } else {
            // 将教室的最早结束时间替换成该讲座的结束时间
            lectureHalls.pop();
            lectureHalls.push(lecture.second);
        }
    }
    std::cout << lectureHalls.size() << std::endl;
    return 0;
}
