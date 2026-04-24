// Last updated: 4/24/2026, 10:42:51 PM
1class Solution {
2public:
3    int find(int m,int n,int maxMove,int i,int j,vector<vector<vector<long long>>> &dp)
4    {
5        if(i <0 || j < 0 || i>=m || j>= n)
6        {
7            return 1;
8        }
9        if(maxMove == 0)
10        {
11            return 0;
12        }
13        if(dp[i][j][maxMove] != -1)
14        {
15            return dp[i][j][maxMove];
16        }
17        dp[i][j][maxMove]=((long long)find(m,n,maxMove-1,i-1,j,dp)+find(m,n,maxMove-1,i+1,j,dp)+find(m,n,maxMove-1,i,j-1,dp)+find(m,n,maxMove-1,i,j+1,dp))%(long long)(1e9+7);
18        return dp[i][j][maxMove];
19    }
20    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
21        vector<vector<vector<long long>>> dp(m,vector<vector<long long>>(n,vector<long long>(maxMove+1,-1)));
22        return find(m,n,maxMove,startRow,startColumn,dp);
23    }
24};