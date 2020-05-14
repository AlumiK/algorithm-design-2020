#include <vector>
#include <iostream>
#include <algorithm>

// A job has start time, finish time and profit.
class Job {
public:
    int start;
    int finish;
    int profit;
};

// A utility function that is used for sorting events according to finish time.
bool operator<(const Job &lhs, const Job &rhs) {
    return lhs.finish < rhs.finish;
}

// A Binary Search based function to find the latest job (before current job) that doesn't conflict with current
// job. "index" is index of the current job. This function returns -1 if all jobs before index conflict with it.
// The vector jobs is sorted in increasing order of finish time.
int binarySearch(const std::vector<Job> &jobs, const int index) {
    // Initialize 'lo' and 'hi' for Binary Search.
    auto lo = 0;
    auto hi = index - 1;

    // Perform binary Search iteratively.
    while (lo <= hi) {
        const auto mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start) {
            if (jobs[mid + 1].finish > jobs[index].start) {
                return mid;
            }
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

// The main function that prints the maximum possible profit from given jobs.
int main() {
    int n;
    std::cin >> n;
    std::vector<Job> jobs(n);
    for (auto &job : jobs) {
        std::cin >> job.start >> job.finish >> job.profit;
    }

    // Sort jobs according to finish time.
    sort(begin(jobs), end(jobs));

    // Create an array to store solutions of sub-problems. table[i]
    // stores the profit for jobs till arr[i] (including arr[i]).
    std::vector<int> table(n);
    table[0] = jobs[0].profit;

    // Fill entries in table using recursive property.
    for (auto i = 1; i < n; ++i) {
        // Find profit including the current job.
        auto profit = jobs[i].profit;
        const auto latestJob = binarySearch(jobs, i);
        if (latestJob != -1)
            profit += table[latestJob];

        // Store maximum of including and excluding the current job.
        table[i] = std::max(profit, table[i - 1]);
    }

    std::cout << table[n - 1] << std::endl;
    return 0;
}
