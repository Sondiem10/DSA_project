# Longest Common Substring Problem

## Overview
The Longest Common Substring (LCS) problem is a classic problem in computer science and string processing. It involves finding the longest substring that is present in two given strings. A substring is a contiguous sequence of characters within a string, and the goal is to identify the maximum-length substring common to both input strings.

## Applications
1. **Bioinformatics**: Comparing DNA, RNA, or protein sequences.
2. **Text Processing**: Plagiarism detection and file comparison tools.
3. **Data Compression**: Identifying redundancies in data streams.
4. **Information Retrieval**: Matching query terms with database entries.
5. **Version Control**: Highlighting differences between file versions.

## Time Complexity
The most common approach to solve the LCS problem is using **Dynamic Programming**, which yields a time complexity of:

- **Time Complexity**: O(m*n), where m and n are the lengths of the two strings.
- **Space Complexity**:
  - O(m*n) for a 2D DP table.
  - Can be optimized to O(min(m, n)) using rolling arrays.

## Input Format
The input consists of:
1. A string `A`.
2. A string `B`.

## Example Input
```plaintext
A = "abcdef"
B = "zcdemf"
```

## Output Format
The output includes:
1. The length of the longest common substring.
2. The substring itself.

## Example Output
```plaintext
Length: 3
Substring: "cde"
```
