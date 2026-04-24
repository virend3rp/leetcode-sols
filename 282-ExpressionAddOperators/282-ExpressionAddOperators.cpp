// Last updated: 4/24/2026, 10:13:49 PM
class Solution {
public:
    vector<string> addOperators(string s, int target) {
        vector<string> ans;
        helper(s, target, 0, "", 0, 0, ans);
        return ans;
    }
    void helper(string s, int target, int start , const string &path, long eval, long prev, vector<string> &ans){
        // base case
        if(start == s.length()){
            if(eval == target){
                ans.push_back(path);
                return;
            }
        }
        string currStr;
        long num = 0;
        for(int i = start; i< s.length();i++){
            // handle for start = 0
            if( i > start && s[start] == '0') return;
            currStr += s[i];
            num = num*10 + s[i]-'0';
            if(start == 0){
                helper(s,target,i+1, path + currStr, num, num, ans);
            }else{
                helper(s,target,i+1, path + "+" + currStr, eval + num, num, ans);
                helper(s,target,i+1, path + "-" + currStr, eval - num , -num, ans);
                helper(s,target,i+1, path + "*" + currStr, eval - prev + prev*num, prev*num, ans);
            }
        }

    }
};