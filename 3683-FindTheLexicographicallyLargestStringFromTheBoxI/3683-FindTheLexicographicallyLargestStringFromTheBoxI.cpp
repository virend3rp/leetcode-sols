// Last updated: 4/24/2026, 10:04:08 PM
class Solution {
public:
    string answerString(string s, int m) {
        if(m == 1) return s;
        int n = s.size();
        int sz = n - m + 1;

        char ch = 'a';

        for(auto x : s){
            if(x > ch){
                ch = x;
            }
        }

        vector<int> ind;

        for(int i=0;i<n;i++){
            if(s[i] == ch){
                ind.push_back(i);
            }
        }

        string ans = "";

        for(auto i : ind){
            int mx = min(n-i , sz);
            string temp = s.substr(i , mx);
            if(temp > ans){
                ans = temp;
            }
        }

        return ans;
    }
};