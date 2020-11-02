# Count Smaller Numbers

## Description

You are given an integer array `nums`, and you are going to return its count array `counts`, where `counts[i]` is the number of elements smaller than  `nums[i]` to the right of `nums[i]` in `nums`.

## Input

The first line of the input is an integer `n`, which indicates how many integers below. Each of the next `n` lines is a non-negative integer which constitutes `nums`.

## Output

There are `n` lines in the output. Each line is the number of elements smaller than `nums[i]` to the right of `nums[i]` in `nums`.

## Hint

A naive brute force algorithm is trivial. You MUST do better than that. Try your best to get the smallest time complexity.

## Example

### Input

```text
4
5
2
6
1
```

### Output

```text
2
1
1
0
```

### Explanation

Input Array `nums = {5, 2, 6, 1}`

Output Array `counts = {2, 1, 1, 0}`

To the right of 5 there are 2 smaller elements (2 and 1).

To the right of 2 there is only 1 smaller element (1).

To the right of 6 there is 1 smaller element (1).

To the right of 1 there is 0 smaller element.
