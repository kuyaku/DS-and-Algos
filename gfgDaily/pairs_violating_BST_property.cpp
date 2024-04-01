// given is the binary tree, we have to find the number of pairs violating the propery of binary tree
// properties of binary tree:
// Every node is greater than its left child and less than its right child
// Every node is greater than the maximum value in its left subtree and less than the minimum value in its right subtree
// The maximum in the left sub-tree must be less than the minimum in the right subtree

// in simple sense, a node must be greater than all of left, and smaller than all of right, and it is true for all nodes

// Solution (intuition)
// 1. Brute force: we can find the inorder traversal of the tree, and find the number of pairs violating the property
// TC: O(N^2) , two loops to get all pairs

// 2. Optimized solution: We can observe that the answer is simply to find how far the array is from sorted
// in other sense, how many swaps we have to make, to make the array sorted
// this is another problem called as [count inversions: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1]
// solving for count inversion we have to use merge sort, and find the count (the number of times we have to select from the second array while merging)
// TC: N * (log(N)), since merge sort is used


class Solution {
    private:
    void inorderTraversal(Node *root, vector<int> &inorder) {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }
    
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp(high - low + 1);
        int i = low, j = mid + 1, count = 0, idx = 0;
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[idx] = arr[i];
                i++;
            } else {
                temp[idx] = arr[j];
                j++; count += (mid - i + 1);
            }
            idx++;
        }
        while (i <= mid) {
            temp[idx] = arr[i];
            i++; idx++;
        }
        while (j <= high) {
            temp[idx] = arr[j];
            j++; idx++;
        }
        
        for (int i = 0; i < (high - low + 1); i++) {
            arr[i + low] = temp[i];
        }
        return count;
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;
        int mid = low + (high - low) / 2;
        int left = mergeSort(arr, low, mid);
        int right = mergeSort(arr, mid + 1, high);
        return left + right + merge(arr, low, mid, high);
    }
    
    int countInversions(vector<int> &arr, int n) {
        return mergeSort(arr, 0, n - 1);
    }
    public:
    int pairsViolatingBST(int n, Node *root) {
        // we just have to find the inorder traversal of binary tree given, then the number of pairs violating the BST property, which
        // are just the number of inversions required to make the array (inorder traversal) sorted, in other words, how much the array is sorted
        vector<int> inorder;
        inorderTraversal(root, inorder);
        return countInversions(inorder, n);
    }
};