// Last updated: 4/24/2026, 10:09:21 PM
class Solution {
public:
    int minSteps(string s, string t) {
        int hash1[26]={0};
        int hash2[26]={0};
        for(int i=0;i<s.size();i++){
            hash1[s[i]-'a']++;
            hash2[t[i]-'a']++;
        }
        int opr=0;
        for(int i=0;i<26;i++){
            int val=hash2[i]-hash1[i];
            if(val>0){
                opr+=val;
            };
        }
        return opr;
    }
};