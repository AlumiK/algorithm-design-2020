#include <vector>
#include <iostream>

void merge(std::vector<std::pair<int, int>> &subVec1, std::vector<std::pair<int, int>> &subVec2,
           std::vector<std::pair<int, int>> &vec, std::vector<int> &count) {
    auto i = 0;
    auto j = 0;
    while (i < subVec1.size() && j < subVec2.size()) {
        if (subVec1[i].first <= subVec2[j].first) {
            vec.push_back(subVec1[i]);
            count[subVec1[i].second] += j;  // 利用归并排序进行计数
            ++i;
        } else {
            vec.push_back(subVec2[j]);
            ++j;
        }
    }
    for (; i < subVec1.size(); ++i) {
        vec.push_back(subVec1[i]);
        count[subVec1[i].second] += j;  // 利用归并排序进行计数
    }
    for (; j < subVec2.size(); ++j) {
        vec.push_back(subVec2[j]);
    }
}

void mergeSort(std::vector<std::pair<int, int>> &vec, std::vector<int> &count) {
    if (vec.size() < 2) {
        return;
    }
    const auto mid = vec.size() / 2;
    std::vector<std::pair<int, int>> subVec1;
    std::vector<std::pair<int, int>> subVec2;
    subVec1.reserve(mid);
    subVec2.reserve(vec.size() - mid);
    for (auto i = 0; i < mid; ++i) {
        subVec1.push_back(vec[i]);
    }
    for (auto i = mid; i < vec.size(); ++i) {
        subVec2.push_back(vec[i]);
    }
    mergeSort(subVec1, count);
    mergeSort(subVec2, count);
    vec.clear();
    merge(subVec1, subVec2, vec, count);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> count(n, 0);
    std::vector<std::pair<int, int>> vec(n);  // 关联每个数和它的序号
    for (auto i = 0; i < n; ++i) { // 保存每个数和它在原数组中的序号，以免在排序过程中打乱顺序
        std::cin >> vec[i].first;
        vec[i].second = i;
    }
    mergeSort(vec, count);
    for (const auto i : count) {
        std::cout << i << std::endl;
    }
    return 0;
}
