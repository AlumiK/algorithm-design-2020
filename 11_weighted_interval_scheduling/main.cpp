#include <vector>
#include <iostream>
#include <algorithm>

class Job {
public:
    int start;
    int finish;
    int profit;
};

bool operator<(const Job &lhs, const Job &rhs) {
    return lhs.finish < rhs.finish;
}

inline int binarySearch(const std::vector<Job> &jobs, const int index) {
    auto lo = 0;
    auto hi = index - 1;
    while (lo <= hi) {
        const auto mid = (lo + hi) / 2;
        if (jobs.at(mid).finish <= jobs.at(index).start) {
            if (jobs.at(mid + 1).finish > jobs.at(index).start) {
                return mid;
            }
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int weightedIntervalScheduling(std::vector<Job> &jobs) {
    sort(begin(jobs), end(jobs));
    std::vector<int> table(jobs.size());
    table.at(0) = jobs.at(0).profit;
    for (auto i = 1; i < jobs.size(); ++i) {
        auto profit = jobs.at(i).profit;
        const auto latestJob = binarySearch(jobs, i);
        if (latestJob != -1) {
            profit += table.at(latestJob);
        }
        table.at(i) = std::max(profit, table.at(i - 1));
    }
    return table.at(jobs.size() - 1);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Job> jobs(n);
    for (auto &job : jobs) {
        std::cin >> job.start >> job.finish >> job.profit;
    }
    std::cout << weightedIntervalScheduling(jobs) << std::endl;
    return EXIT_SUCCESS;
}
