# Interval Scheduling

## Description

There are `n` tasks, each task starts at `s_i` and ends at `t_i`. For each task, Tom can carry it out or not. Once he starts to undertake a certain task, he must complete it. Additionally, Tom can only perform one task at the same time. Tom is not allowed to carry out a task if its start time is the same as the end time of the previous task.

Tom wants to carry out as many tasks as possible. Please tell him how many tasks he can complete.

## Input

There are multiple test cases. The first line of each test case is a positive integer `n` (1 ≤ `n` ≤ 10^5) indicating the number of total tasks. The second line shows the start time `s_i` of each task. The third line denotes the end time `t_i` of each task (0 ≤ `s_i` < `t_i` ≤ **10^10**).

## Output

Please print the maximum number of tasks that Tom can complete.

## Example

### Input

```text
5
1 2 4 6 8
3 5 7 9 10
```

### Output

```text
3
```
