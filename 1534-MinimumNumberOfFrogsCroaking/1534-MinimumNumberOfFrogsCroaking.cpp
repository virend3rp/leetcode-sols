// Last updated: 4/24/2026, 10:09:06 PM
class Solution {
public:
    int minNumberOfFrogs(string str) {
        unordered_map<char,int> qmap;
        for(int i=0;i<str.size();i++)
        {
            qmap[str[i]]++;
             if(qmap['r']>qmap['c'] or qmap['o']>qmap['c'] or qmap['a']>qmap['c'] or qmap['k']>qmap['c'] or qmap['r'] < qmap['o'] or qmap['r'] < qmap['a'] or qmap['r'] < qmap['k'] or qmap['o'] < qmap['a'] or qmap['o'] < qmap['k'] or qmap['a'] < qmap['k'])
                return -1;
        }
        int x=qmap[str[0]];
        for(auto it:qmap)
            if(qmap[it.first]!=x)
                return -1;
        int vval=0;
        int ans=0;
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='c')
            {
                vval++;
            }
            else if(str[i]=='k')
                vval--;
            ans=max(vval,ans);
        }
            
        return ans;
    }
};