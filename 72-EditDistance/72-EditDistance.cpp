// Last updated: 4/24/2026, 10:16:21 PM
#include<bits/stdc++.h>
class Solution {
public:

    int minDistance(string word1, string word2) {
        int n= word1.length() ;
        int m = word2.length() ;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0)) ;

        for(int j=0;j<=m;j++)
        {
            dp[0][j]= j;
        }

        for(int i=0;i<=n;i++)
        {   
            dp[i][0]=i ;
        }  

        for(int index1=1;index1<=n;index1++)
        {
            for(int index2=1;index2<=m;index2++)
            {
                if(word1[index1-1]==word2[index2-1])
                {
                    dp[index1][index2]=dp[index1-1][index2-1] ;
                }
                else
                {
                    int del= 1+dp[index1-1][index2] ;
                    int repl= 1+ dp[index1-1][index2-1] ;
                    int insert= 1+ dp[index1][index2-1] ;
                    dp[index1][index2]= min(del,min(repl,insert)) ;
                }
            }
        }

        return dp[n][m] ;            
    }
};