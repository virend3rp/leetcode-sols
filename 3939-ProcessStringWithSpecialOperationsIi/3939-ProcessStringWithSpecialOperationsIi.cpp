// Last updated: 4/24/2026, 10:03:32 PM
class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> lengths;
        long long len=0;
        
        for(char c:s){
            if(islower(c)){
                len+=1;
            }
            else if(c=='*'){
                if(len>0)len-=1;
            }else if(c=='#'){
                len*=2;
            }
            lengths.push_back(len);
        }
        if(k>=len) return '.';

        for(int i=s.size()-1;i>=0;--i){
            char c=s[i];
            long long currLen=lengths[i];
            if(islower(c)){
                if(currLen-1==k) return c;
                len-=1;
            }else if(c=='*'){
                len+=1;
            }else if(c=='#'){
                len/=2;
                if(k>=len)k-=len;
            }
            else if(c=='%'){
                k=len-1-k;
            }
        }
        return '.';
    }
};