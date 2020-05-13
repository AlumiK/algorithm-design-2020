#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> findMajorityNumbers(const std::vector<int> &nums) {
    std::vector<int> majorityNumbers;
    auto a = 0, b = 0, cnt1 = 0, cnt2 = 0;
    for (const auto num : nums) {
        if (num == a) {
            ++cnt1;
        } else if (num == b) {
            ++cnt2;
        } else if (cnt1 == 0) {
            a = num;
            ++cnt1;
        } else if (cnt2 == 0) {
            b = num;
            ++cnt2;
        } else {
            --cnt1;
            --cnt2;
        }
    }
    cnt1 = cnt2 = 0;
    for (int num : nums) {
        if (num == a) {
            ++cnt1;
        } else if (num == b) {
            ++cnt2;
        }
    }
    if (cnt1 > nums.size() / 3) {
        majorityNumbers.push_back(a);
    }
    if (cnt2 > nums.size() / 3) {
        majorityNumbers.push_back(b);
    }
    return majorityNumbers;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (auto i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    auto majorityNumbers = findMajorityNumbers(nums);
    sort(begin(majorityNumbers), end(majorityNumbers));
    for (const auto i : majorityNumbers) {
        std::cout << i << std::endl;
    }
    return 0;
}
