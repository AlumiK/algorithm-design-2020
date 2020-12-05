#include <vector>
#include <iostream>

void merge(std::vector<std::pair<int, int>> &subVec1, std::vector<std::pair<int, int>> &subVec2,
           std::vector<std::pair<int, int>> &vec, std::vector<int> &count) {
    auto i = 0;
    auto j = 0;
    while (i < subVec1.size() && j < subVec2.size()) {
        if (subVec1.at(i).first <= subVec2.at(j).first) {
            vec.push_back(subVec1.at(i));
            count.at(subVec1.at(i).second) += j;
            ++i;
        } else {
            vec.push_back(subVec2.at(j));
            ++j;
        }
    }
    for (; i < subVec1.size(); ++i) {
        vec.push_back(subVec1.at(i));
        count.at(subVec1.at(i).second) += j;
    }
    for (; j < subVec2.size(); ++j) {
        vec.push_back(subVec2.at(j));
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
        subVec1.push_back(vec.at(i));
    }
    for (auto i = mid; i < vec.size(); ++i) {
        subVec2.push_back(vec.at(i));
    }
    mergeSort(subVec1, count);
    mergeSort(subVec2, count);
    vec.clear();
    merge(subVec1, subVec2, vec, count);
}

std::vector<int> countSmallerNumbers(std::vector<std::pair<int, int>> &numPairs) {
    std::vector<int> counts(numPairs.size(), 0);
    mergeSort(numPairs, counts);
    return counts;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> numPairs(n);
    for (auto i = 0; i < n; ++i) {
        std::cin >> numPairs.at(i).first;
        numPairs.at(i).second = i;
    }
    const auto ret = countSmallerNumbers(numPairs);
    for (const auto i : ret) {
        std::cout << i << std::endl;
    }
    return EXIT_SUCCESS;
}
