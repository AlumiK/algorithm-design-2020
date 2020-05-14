#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

class DisjointSets {
private:
    std::vector<int> parents;
    std::vector<int> ranks;

public:
    explicit DisjointSets(const int numNodes) {
        for (auto i = 0; i < numNodes; ++i) {
            ranks.push_back(0);
            parents.push_back(i);
        }
    }

    int find(const int u) {
        if (u != parents[u]) {
            parents[u] = find(parents[u]);
        }
        return parents[u];
    }

    void merge(const int u, const int v) {
        const auto parentOfU = find(u);
        const auto parentOfV = find(v);
        if (ranks[parentOfU] > ranks[parentOfV]) {
            parents[parentOfV] = parentOfU;
        } else {
            parents[parentOfU] = parentOfV;
        }
        if (ranks[parentOfU] == ranks[parentOfV]) {
            ranks[parentOfV]++;
        }
    }
};

class Graph {
private:
    int numNodes;
    std::vector<std::pair<double, std::pair<int, int>>> edges;

public:
    explicit Graph(const int numNodes) : numNodes(numNodes) {}

    void addEdge(const int u, const int v, const double weight) {
        edges.push_back({weight, {u, v}});
    }

    double singleLinkageClustering(const int k) {
        sort(begin(edges), end(edges));
        std::vector<double> mstWeights;
        DisjointSets disjointSets(numNodes);
        for (const auto &edge: edges) {
            const auto parentOfU = disjointSets.find(edge.second.first);
            const auto parentOfV = disjointSets.find(edge.second.second);
            if (parentOfU != parentOfV) {
                mstWeights.push_back(edge.first);
                if (mstWeights.size() >= numNodes - 1) {
                    break;
                }
                disjointSets.merge(parentOfU, parentOfV);
            }
        }
        sort(begin(mstWeights), end(mstWeights));
        return mstWeights[mstWeights.size() - k + 1];
    }
};


double euclideanDistance(const std::pair<int, int> &u, const std::pair<int, int> &v) {
    return sqrt(pow((u.first - v.first), 2) + pow((u.second - v.second), 2));
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> nodes(n);
    for (auto &node : nodes) {
        std::cin >> node.first >> node.second;
    }
    Graph graph(n);
    for (auto i = 0; i < n - 1; ++i) {
        for (auto j = i + 1; j < n; ++j) {
            graph.addEdge(i, j, euclideanDistance(nodes[i], nodes[j]));
        }
    }
    std::cout << std::fixed << std::setprecision(2) << graph.singleLinkageClustering(k) << std::endl;
    return 0;
}
