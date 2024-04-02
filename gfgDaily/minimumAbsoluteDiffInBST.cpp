// https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

// [EASY - MEDIUM]

// given is the binary search tree, we have to find the minimum absolute difference between any two nodes

// ideas: inorder traversal of BST gives the sorted order, so the minimum absolute differnce can be found from consecutive pairs
// sol1: store the inorder traversal: SC: O(N) 
// sol2: just store the last, and find the min absolute diff: SC: O(1)
// TC (both): O(N), each node is visited once

#include <bits/stdc++.h>

using namespace std;


struct Node {
    Node *left = nullptr;
    Node *right = nullptr;
    int data = 0;
};
class Solution
{
    private:
    void inorderTraversal(Node *root, vector<int> &inorder) {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }
    
    int minAbsoluteDiff(vector<int> &inorder, int n) {
        int mini = INT_MAX;
        for (int i = 1; i < n; i++) {
            mini = min(mini, inorder[i] - inorder[i - 1]);
        }
        return mini;
    }
    public:
    int absolute_diff(Node *root) {
        // inorder traversal will give sorted order, then we can find the minimum absolute difference between neighbouring pairs
        vector<int> inorder;
        inorderTraversal(root, inorder);
        return minAbsoluteDiff(inorder, inorder.size());
    }
};

class Solution2
{
    private:
    void inorderModified(Node *root, int &last, int &mini) {
        if (root->left) inorderModified(root->left, last, mini);
        if (last != -1) mini = min(mini, abs(last - root->data));
        last = root->data;
        if (root->right) inorderModified(root->right, last, mini);
    }
    public:
    int absolute_diff(Node *root) {
        // another solution is that, we don't actually have to store the whole inorder traversal, instead, we just can store the last value, and find the minimum absolute difference with the current value
        int last = -1, mini = INT_MAX;
        inorderModified(root, last, mini);
        return mini;
    }
};