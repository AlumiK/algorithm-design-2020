#include <iostream>
#include <vector>

int main() {
    int W, n;
    std::cin >> W >> n;
    std::vector<int> wt(n);
    std::vector<int> val(n);
    for (auto i = 0; i < n; ++i) {
        std::cin >> wt.at(i) >> val.at(i);
    }
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1));
    for (auto i = 0; i <= n; ++i) {
        for (auto w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp.at(i).at(w) = 0;
            } else if (wt.at(i - 1) <= w) {
                dp.at(i).at(w) = std::max(
                        val.at(i - 1) + dp.at(i - 1).at(w - wt.at(i - 1)),
                        dp.at(i - 1).at(w));
            } else {
                dp.at(i).at(w) = dp.at(i - 1).at(w);
            }
        }
    }
    std::cout << dp.at(n).at(W) << std::endl;
    return EXIT_SUCCESS;
}
