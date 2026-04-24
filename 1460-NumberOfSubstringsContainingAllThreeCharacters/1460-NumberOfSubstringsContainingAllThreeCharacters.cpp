// Last updated: 4/24/2026, 10:09:23 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int lastseen[3]={-1,-1,-1};
        int count=0;
        for(int i=0;i<n;i++){
            lastseen[s[i] - 'a'] = i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                count+=1+min({lastseen[1],lastseen[0],lastseen[2]});   
            }
        }
    return count;   
    }
};