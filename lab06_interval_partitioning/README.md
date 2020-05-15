# Interval Partitioning

## Description

Imagine:

- There are `n` lectures, each with a fixed start and end time.
- Each lecture needs a lecture hall.
- There can only be one lecture in one lecture hall at the same time.
- Two consecutive lectures are still allowed to take place in the same lecture hall if the start time of the second lecture is equal to the end time of the first one.

You are required to find the minimum number of lecture halls needed for scheduling all lectures.

## Input

The first line is a positive integer `n`, indicating how many lectures to be scheduled. Each of the next `n` lines has 2 integers, which represent the start time and end time of each lecture. Time starts at 0.

## Output

The output is the minimum number of lecture halls needed.

## Example

### Input 1

```text
5
1 23
12 28
25 35
27 80
36 50
```

### Output 1

```text
3
```

### Input 2

```text
4
1 3
5 7
5 8
2 5
```

### Output 2

```text
2
```
