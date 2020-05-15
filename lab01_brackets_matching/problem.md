# Brackets Matching

## Description

The input string contains only 4 types of brackets, `()`, `[]`, `<>` and `{}`. The goal is to determine whether each sequence of brackets is matched. If the input string has multiple levels of enclosure, the order of brackets must be `<>`, `()`, `[]`, `{}` from inside to outside. 

For example, if we input `[()]`, the output should be `YES`, while input `([])` or `[(]`, the output should be `NO`.

## Input

The first line of the input is an integer `n`, indicating how many strings below. The next `n` lines, each line is a string consisting of brackets and no longer than 255.

## Output

There are `n` lines in the output, each line is either `YES` or `NO`.

## Example

### Input

```text
5
{}{}<><>()()[][]
{{}}{{}}<<>><<>>(())(())[[]][[]]
{{}}{{}}<<>><<>>(())(())[[]][[]]
{<>}{[]}<<<>><<>>>((<>))(())[[(<>)]][[]]
><}{{[]}<<<>><<>>>((<>))(())[[(<>)]][[]]
```

### Output

```text
YES
YES
YES
YES
NO
```
