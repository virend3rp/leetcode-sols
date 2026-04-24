// Last updated: 4/24/2026, 10:17:04 PM
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        int j =0; 
        for(int i = 0; i < n-m+1 ; i++){
            j = 0;
            while( j < m and haystack[i+j]== needle[j]){
                j++;
            }
            if(j == m) return i;
        }
        return -1;
    }
};