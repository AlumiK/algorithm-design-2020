# Scheduling to Minimize Maximum Lateness

## Description

Imagine:

- You're a student and started late to work on your assignments.
- You have ![n](https://render.githubusercontent.com/render/math?math=n) assignments. Each one has an expected duration and a deadline.
- If you started working on an assignment, you could not stop it until you complete it.
- You want to minimize the maximum lateness of handing in your assignments.

Formally:

- Every assignment ![j](https://render.githubusercontent.com/render/math?math=j) has an expected duration ![t_j](https://render.githubusercontent.com/render/math?math=t_j) and a deadline ![d_j](https://render.githubusercontent.com/render/math?math=d_j).
- If assignment ![j](https://render.githubusercontent.com/render/math?math=j) starts at ![s_j](https://render.githubusercontent.com/render/math?math=s_j), then it finishes at ![f_j=s_j+t_j](https://render.githubusercontent.com/render/math?math=f_j%3Ds_j%2Bt_j).
- The lateness of an assignment ![j](https://render.githubusercontent.com/render/math?math=j) is defined by ![l_j=\max(0,f_j-d_j)](https://render.githubusercontent.com/render/math?math=l_j%3D%5Cmax(0%2Cf_j-d_j)).
- You need to arrange the schedule to minimizes the maximum lateness ![L=\max_{j} l_j](https://render.githubusercontent.com/render/math?math=L%3D%5Cmax_%7Bj%7D%20l_j).

## Input

The first line is a positive integer ![n](https://render.githubusercontent.com/render/math?math=n) (1 ≤ ![n](https://render.githubusercontent.com/render/math?math=n) ≤ 10^4), indicating how many assignments need to be scheduled. Each of the next ![n](https://render.githubusercontent.com/render/math?math=n) lines has 2 integers, which represent the expected duration ![t_j](https://render.githubusercontent.com/render/math?math=t_j) and the deadline ![d_j](https://render.githubusercontent.com/render/math?math=d_j) for each assignment (1 ≤ ![t_j](https://render.githubusercontent.com/render/math?math=t_j), ![d_j](https://render.githubusercontent.com/render/math?math=d_j) ≤ 10^3). Time starts at 0.

## Output

Please print the maximum lateness ![L](https://render.githubusercontent.com/render/math?math=L).

## Example

### Input

```text
5
3 4
2 7
1 8
4 8
2 10
```

### Output

```text
2
```
