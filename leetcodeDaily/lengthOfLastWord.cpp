// https://leetcode.com/problems/length-of-last-word/description/?envType=daily-question&envId=2024-04-01

// [EASY]

// given a string, consisting of words and spaces, return the length of the last word in the string

class Solution {
public:
    int lengthOfLastWord(string s) {
        int maxi = 0, i = 0, n = s.size();
        while (i < n) {
            if (s[i] != ' ') {
                int j = i;
                while (j < n && s[j] != ' ') {
                    j++;
                }
                maxi = j - i;
                i = j;
            }
            i++; 
        }
        return maxi;
    }
};