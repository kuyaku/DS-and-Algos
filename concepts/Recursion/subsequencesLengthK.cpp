#include <bits/stdc++.h>

using namespace std;

void subsequencesLengthK(int idx, int n, vector<int> &arr, int k, vector<vector<int>> &subs, vector<int> curr) {
    if (curr.size() == k) {
        subs.push_back(curr);
        curr = {};
    }
    if (idx == n) return;
    if ((n - idx + curr.size()) < k) return;
    curr.push_back(arr[idx]);
    subsequencesLengthK(idx + 1, n, arr, k, subs, curr);
    curr.pop_back();
    subsequencesLengthK(idx + 1, n, arr, k, subs, curr);
}

void print1d(vector<int> &arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void print2d(vector<vector<int>> &arr, int n) {
    for (int i = 0; i < n; i++) print1d(arr[i], arr[i].size());
}

int main() {
    vector<int> arr = {1, 2, 4, 3};
    int n = arr.size();
    int k = 3;
    vector<vector<int>> subs;
    subsequencesLengthK(0, n, arr, k, subs, {});
    print2d(subs, subs.size());
    cout << "Total subsequences: " << subs.size() << endl;
    return 0;
}