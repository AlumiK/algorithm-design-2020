#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> findMajorityNumbers(const std::vector<int> &nums) {
    std::vector<int> majorityNumbers;
    auto a = 0;
    auto b = 0;
    auto countA = 0;
    auto countB = 0;
    for (const auto num : nums) {
        if (num == a) {
            ++countA;
        } else if (num == b) {
            ++countB;
        } else if (countA == 0) {
            a = num;
            ++countA;
        } else if (countB == 0) {
            b = num;
            ++countB;
        } else {
            --countA;
            --countB;
        }
    }
    countA = 0;
    countB = 0;
    for (const auto num : nums) {
        if (num == a) {
            ++countA;
        } else if (num == b) {
            ++countB;
        }
    }
    if (countA > nums.size() / 3) {
        majorityNumbers.push_back(a);
    }
    if (countB > nums.size() / 3) {
        majorityNumbers.push_back(b);
    }
    sort(begin(majorityNumbers), end(majorityNumbers));
    return majorityNumbers;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (auto &num : nums) {
        std::cin >> num;
    }
    const auto ret = findMajorityNumbers(nums);
    for (const auto i : ret) {
        std::cout << i << std::endl;
    }
    return EXIT_SUCCESS;
}
