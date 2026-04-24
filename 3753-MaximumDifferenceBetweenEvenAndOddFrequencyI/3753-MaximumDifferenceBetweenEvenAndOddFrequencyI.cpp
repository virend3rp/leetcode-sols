// Last updated: 4/24/2026, 10:04:01 PM
class Solution {
public:
    int maxDifference(string s) {
        int o=INT_MIN;
        int e=INT_MAX;
        map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(m[s[i]]&1)
            o = max(m[s[i]],o);
            else
            e = min(m[s[i]],e);
        }
        return o-e;
    }
};