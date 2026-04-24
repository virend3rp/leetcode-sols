// Last updated: 4/24/2026, 10:06:52 PM
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26, 0);
        for(int i = 0; i < s.size(); i++){
            a[s[i] - 'a']++; //s[i] - 'a' is used to convert char into integer index.
         }


        for(int i = 0; i < t.size(); i++){
            a[t[i] - 'a']--;
        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(a[i] > 0) count+=a[i]; 
            else count-=a[i];
        }
        return count;
    }
};