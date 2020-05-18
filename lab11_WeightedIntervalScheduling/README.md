# Weighted Interval Scheduling

## Description

You are given n jobs where every job is represented by the following three attributes.

- Start Time
- End Time
- Profit Associated (≥ 0)

You need to find the maximum profit subset of jobs such that no two jobs in the subset overlap.

## Input

The first line is a positive integer `n` (`n` < 1000), indicating how many jobs to be scheduled. Each of the next n lines has 3 integers, which represent the start time, end time and the profit of each job. Time starts at 0.

## Output

The output is the maximum profit possible.

## Hint

Use binary search to get the optimal time complexity.

## Example

### Input

```text
4
1 3 10
2 4 100
3 5 20
5 6 30
```

### Output

```text
130
```

### Explanation

- Job 1: {1, 3, 10} 
- Job 2: {2, 4, 100}
- Job 3: {3, 5, 20}
- Job 4: {5, 6, 30}

We can get the maximum profit by scheduling Job 2, 4. The maximum profit is 130.

Note that there is a longer schedule possible for Job 1, 3 and 4, but the profit with this schedule is 10 + 20 + 30 = 60 which is less than 130.
