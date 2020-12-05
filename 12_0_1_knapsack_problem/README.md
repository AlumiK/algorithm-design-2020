# 0-1 Knapsack Problem

## Description

Given the weights and values of `n` items, put these items in a knapsack of capacity `W`. You should find a way to maximize the total value of the items put into the knapsack.

Specifically, you will be given two integer arrays `val[0..n-1]` and `wt[0..n-1]` which represent the values and weights of `n` items, respectively, and an integer `W` which denotes the knapsack's capacity. You should find the subset of items achieving maximum sum of values. Recall that the sum of the weights of these items is smaller than or equal to `W`.

You cannot break an item, and should either pick the whole item or do not pick it (0-1 property).

## Input

The first line has two positive integers `W` (`W` ≤ 200) and `n` (`n` ≤ 30), indicating the capacity of the knapsack as well as the number of items, respectively. Each of the next `n` lines has 2 integers, which respectively denote the weight and value of each item.

## Output

The output is the maximum sum of the value of the items put into the knapsack.

## Example

### Input

```text
10 4
2 1
3 3
4 5
7 9
```

### Output

```text
12
```
