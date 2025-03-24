## 📁 Tabulation Solutions

This folder contains Dynamic Programming solutions solved using the **Tabulation (Bottom-Up)** approach.

---

## 1 Problem: Longest Common Subsequence (LCS) (tabu_prob_1.cpp)

# Description
Given two strings, the goal is to calculate the length of their Longest Common Subsequence (LCS).  
A common subsequence is a sequence that appears in both strings in the same relative order but not necessarily consecutively.

# Approach: Tabulation (Bottom-Up)
- **Method**: Iterative method that builds a DP table.
- **Idea**: Create a 2D DP table where `dp[i][j]` represents the LCS length for the substrings `s1[0...i-1]` and `s2[0...j-1]`.

---

