// Last updated: 4/29/2026, 4:47:58 PM
1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        int n = haystack.size();
5        int m = needle.size();
6
7        int j =0; 
8        for(int i = 0; i < n-m+1 ; i++){
9            j = 0;
10            while( j < m and haystack[i+j]== needle[j]){
11                j++;
12            }
13            if(j == m) return i;
14        }
15        return -1;
16    }
17};