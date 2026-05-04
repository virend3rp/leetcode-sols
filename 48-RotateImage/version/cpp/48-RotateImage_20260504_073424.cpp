// Last updated: 5/4/2026, 7:34:24 AM
1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        int n=matrix.size();
5        vector<vector<int>> ans(n, vector<int>(n));
6        for(int i=0;i<n;i++){
7            for(int j=i+1;j<n;j++){
8                swap(matrix[i][j],matrix[j][i]);
9            }
10        }
11       for (int i = 0; i < n; i++) {
12            reverse(matrix[i].begin(), matrix[i].end());
13        }
14    }
15};