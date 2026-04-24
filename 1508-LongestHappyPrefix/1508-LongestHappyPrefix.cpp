// Last updated: 4/24/2026, 10:09:12 PM
class Solution 
{
    vector<int> getLps(string s)
    {
        int size = s.length();
        vector<int> lps(size , 0);
        int j = 0;
        for(int i = 1 ; i < size ; i++)
        {
            while(j > 0 && s[i] != s[j])
            {
                j = lps[j-1];
            }
            if(s[i] == s[j])
            {
                lps[i] = j + 1;
                j++;
            }
        }

        return lps;
    }

public:
    string longestPrefix(string s) 
    {
        vector<int> lps = getLps(s);
        return s.substr(0,lps[s.size() - 1]);
    }
};