# Shortest Path

## Description

There are `n` nodes and `m` undirected edges in the graph (`n` < 1000, `m` < 10000). Each edge has a fixed length. Please find the shortest path between two given nodes `s` and `t` in the graph.

## Input

The first line has 4 integers: `n` (the number of nodes), `m` (the number of edges), `s` (the ID of the source node), and `t` (the ID of the destination node). Each of the following `m` lines contain 3 integers, the IDs of two nodes, and the length of the edge between these two nodes (each length is greater than 0).

## Output

The first line is the length of the shortest path from `s` to `t`. The second line contains the IDs of each node on the shortest path. If there are multiple shortest paths, the one with the smallest lexicographic order is required. If there is no path from the source node to the destination node, please output `-1`.

## Example

### Input

```text
3 3 1 3
1 3 3
1 2 1
2 3 1
```

### Output

```text
2
1 2 3
```
