// https://leetcode.com/problems/isomorphic-strings/?envType=daily-question&envId=2024-04-02

// [EASY]

// given two strings s and t, determine if they are isomorphic.

// Isomorphic strings: Two string s and t are isomorphic if the characters in s can be replaced to get t
// Ex: egg and add : True, since e -> a and g -> d
// foo and bar : False, since f->b, o->a, o->r (inconsistency)

#include <bits/stdc++.h>
using namespace std;


// transform each string into some number, like each character to index, simultaneously.
// if there you see the inconsistency, return false, else return true

// TC: O(N)
// SC: 2 * O(256)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // we transform the strings with numbers
        vector<int> m1(256, 0), m2(256, 0); // ascii characters from 0 to 255
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};


// remember the character conversion, if some inconsistency arises, return false
// remember to treat each string as primary string (from (string) -> to (string)), to neutralize the fact that s -> t but not t -> s

// TC: 2 * O(N)
// SC: 2 * O(N)
class Solution2 {
private:
    bool solve(string s, string t, int n) {
        unordered_map<char, char> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = t[i];
            } else {
                if (mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        return solve(s, t, n) && solve(t, s, n); // take both string as primary
    }
};