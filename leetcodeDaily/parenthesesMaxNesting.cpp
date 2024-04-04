// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=daily-question&envId=2024-04-04

// [EASY]

// problem is pretty much easy, given is a valid string, we have to find the nesting depth of the parentheses

// TC: O(N)  // just need one traversal
// SC: O(1) // just need two variables, to store ans, and currDepth

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int currDepth = 0, maxDepth = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                currDepth--;
            }
            else if (s[i] == '(') {
                currDepth++;
                maxDepth = max(currDepth, maxDepth);
            }
        }
        return maxDepth;
    }
};