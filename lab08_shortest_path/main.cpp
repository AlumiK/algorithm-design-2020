#include <queue>
#include <vector>
#include <limits>
#include <iostream>
#include <unordered_map>

#define NUL_NODE -1

class Node {
public:
    int distance;
    int prevNode;
    bool isVisited = false;
    std::unordered_map<int, int> adjacency;

    Node(const int distance, const int prevNode) : distance(distance), prevNode(prevNode) {}
};

int main() {
    int numNodes, numEdges, source, destination;
    std::cin >> numNodes >> numEdges >> source >> destination;
    --source, --destination;

    std::vector<Node> nodes;
    nodes.reserve(numNodes);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    for (auto i = 0; i < numNodes; ++i) {
        nodes.emplace_back(i == destination ? 0 : std::numeric_limits<int>::max(), NUL_NODE);
    }

    for (auto i = 0; i < numEdges; ++i) {
        int a, b, distance;
        std::cin >> a >> b >> distance;
        --a, --b;
        if (nodes[a].adjacency.find(b) == end(nodes[a].adjacency) || distance < nodes[a].adjacency[b]) {
            nodes[a].adjacency[b] = distance;
            nodes[b].adjacency[a] = distance;
        }
    }

    pq.push({0, destination});
    while (!pq.empty()) {
        const auto curNodeId = pq.top().second;
        if (curNodeId == source) {
            break;
        }
        pq.pop();
        auto &curNode = nodes[curNodeId];
        curNode.isVisited = true;
        for (const auto &edge : curNode.adjacency) {
            const auto nextNodeId = edge.first;
            auto &nextNode = nodes[nextNodeId];
            if (!nextNode.isVisited) {
                const auto newDistance = curNode.distance + edge.second;
                if (newDistance < nextNode.distance) {
                    nextNode.distance = newDistance;
                    nextNode.prevNode = curNodeId;
                    pq.push({newDistance, nextNodeId});
                } else if (newDistance == nextNode.distance && nextNode.prevNode > curNodeId) {
                    nextNode.prevNode = curNodeId;
                }
            }
        }
    }

    auto node = &nodes[source];
    if (node->prevNode == NUL_NODE) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << node->distance << std::endl;
        std::cout << source + 1;
        for (; node->prevNode != NUL_NODE; node = &nodes[node->prevNode]) {
            std::cout << ' ' << node->prevNode + 1;
        }
        std::cout << std::endl;
    }
    return 0;
}
