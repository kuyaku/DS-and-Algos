// notes: when dealing with problems involving substrings, it's worth considering if there is a 
// mathematical pattern or relation or formula that can help optimize the solution
// taking recursion to generate (or using two nested loops) is not a good idea

// https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

// [MEDIUM]

// Given is a number string, we have to generate all the substrings, and find the sum of each number corresponding to the substring
// since the ans can be large, use modulo 10^9 + 7

// solution: observation / intuition

// since in substring problem there may be underlying relation between substrings (start taking substrings from start or end)
// we try to generate the substrings upto an index i
// we see that there is a relation to the previous, ie currSum = prevSum * 10 + (i + 1) * (s[i] - '0')
// this is kind of 1d DP, or can be space optimized with just one prev variable


// TC: O(N) : optimized
// SC: O(1) : optimized

// brute force would be to generate all the substring using nested loops (O(N^2)) and calculate the sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        // usually rec with substrings is a bad idea, but I will check further
        int M = 1e9 + 7, n = s.size();
        long long ans = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            long long curr = (prev * 10 + (i + 1) * (s[i] - '0')) % M;
            ans += curr;
            ans %= M;
            prev = curr;
        }
        return ans;
    }
};