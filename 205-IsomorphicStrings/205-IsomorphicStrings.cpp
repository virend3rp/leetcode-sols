// Last updated: 4/24/2026, 10:14:33 PM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        map<char, char> ms;
        map<char, char> mt;
        for(int i=0;i<s.length();i++)
        {
            if(ms.find(s[i]) == ms.end() && mt.find(t[i]) == mt.end())
            {
                ms[s[i]] = t[i];
                mt[t[i]] = s[i];
            }
            else if(ms[s[i]] != t[i] && mt[t[i]] != s[i])
                return false;
        }
        return true;
    }
};