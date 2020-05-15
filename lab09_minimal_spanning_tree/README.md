# Minimal Spanning Tree

## Description

Imagine:

- There are `n` bookstores located in your area and you want to visit all of them.
- Each bookstore can be reached via another bookstore.
- Every path has a positive distance (>0).
- The sum of the distances of all chosen paths must be minimal.

Please find out the minimum sum of distances of the paths that connect all bookstores.

## Input

The first line is an integer `n` (`n` < 100),indicating how many bookstores are in your area. The following `n` lines are the adjacency matrix of the undirected graph consists of all bookstores.

## Output

The minimum sum of distances of the paths that connect all bookstores.

## Example

### Input

```text
4
0 2 4 0
2 0 3 5
4 3 0 1
0 5 1 0
```

### Output

```text
6
```
