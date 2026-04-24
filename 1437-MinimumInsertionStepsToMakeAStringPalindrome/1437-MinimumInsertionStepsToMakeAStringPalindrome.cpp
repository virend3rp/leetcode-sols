// Last updated: 4/24/2026, 10:09:29 PM
class Solution {
public:    // MEMOIZATION 
  int solve( int i , int j , string &s1 , string &s2 , vector<vector<int>>&dp){
          
        if( i<0 || j<0 )   return 0 ;
        if( dp[i][j]!=-1)   return dp[i][j];
         if(s1[i] == s2[j]) 
              return  dp[i][j]= 1 + solve( i-1,j-1,s1,s2,dp);
      return  dp[i][j] =  max( solve( i-1 ,j ,s1,s2,dp) , solve( i , j-1 ,s1,s2,dp));
    }

    int longestPalindromeSubseq(string s) {
         int n = s.size();  
         string t = s;
         int m = t.size();
         vector<vector<int>> dp( n , vector<int>( m ,-1));
         reverse( t.begin() , t.end());
         return solve( n-1 ,m-1 ,s ,t, dp);
    }
    int minInsertions(string s) {
        int l1=longestPalindromeSubseq(s);
        return s.size()-l1;
    }
};