# Single-linkage Clustering

## Description

You are given `n` nodes in a two-dimensional space. You want to use single-linkage clustering method to find `k` clusters. This is equivalent to finding an MST (Minimum Spanning Tree) of these nodes and deleting `k-1` longest edges. Your job is to output the length of the (k-1)-th longest edge of the MST.

## Input

There are multiple cases. For each case, the first line has two integers `n` and `k` (2 ≤ `k` ≤ `n` ≤ 100). The following `n` lines give the coordinates of `n` nodes. You may use Euclidean distance to measure the distance between two nodes. All coordinates are integers.

## Output

For each case, output the length of the (k-1)-th longest edge of the MST. The precision is set to 2 digits after the decimal point.

## Example

### Input

```text
6 2
1 1
2 1
1 2
3 3
4 2
4 3
```

### Output

```text
2.24
```
