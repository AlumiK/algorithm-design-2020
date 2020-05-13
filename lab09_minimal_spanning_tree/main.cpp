#include <vector>
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
    std::vector<std::pair<int, std::pair<int, int>>> edges;

public:
    explicit Graph(const int numNodes) : numNodes(numNodes) {}

    void addEdge(const int u, const int v, const int weight) {
        edges.push_back({weight, {u, v}});
    }

    int kruskalMST() {
        auto mstWeight = 0;
        auto numEdges = 0;
        sort(begin(edges), end(edges));
        DisjointSets disjointSets(numNodes);
        for (auto &edge: edges) {
            const auto parentOfU = disjointSets.find(edge.second.first);
            const auto parentOfV = disjointSets.find(edge.second.second);
            if (parentOfU != parentOfV) {
                mstWeight += edge.first;
                if (++numEdges >= numNodes - 1) {
                    break;
                }
                disjointSets.merge(parentOfU, parentOfV);
            }
        }
        return mstWeight;
    }
};

int main() {
    int numNodes;
    std::cin >> numNodes;
    Graph graph(numNodes);
    for (auto i = 0; i < numNodes; ++i) {
        for (auto j = 0; j < numNodes; ++j) {
            int weight;
            std::cin >> weight;
            if (weight > 0 && i > j) {
                graph.addEdge(i, j, weight);
            }
        }
    }
    std::cout << graph.kruskalMST() << std::endl;
    return 0;
}
