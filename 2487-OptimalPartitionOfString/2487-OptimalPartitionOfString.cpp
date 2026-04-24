// Last updated: 4/24/2026, 10:06:21 PM
class Solution {
public:
    int partitionString(string s) {
        vector<int> lastseen(26,-1);
        int start=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(lastseen[ch-'a']>=start){
                start=i;
                count++;
            }
            lastseen[ch-'a']=i;
        }
        return count+1;
    }
};