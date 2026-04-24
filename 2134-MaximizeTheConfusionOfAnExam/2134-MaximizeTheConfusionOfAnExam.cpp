// Last updated: 4/24/2026, 10:07:29 PM
class Solution {
public:
    int maxConsecutiveAnswers(string answerkey, int k) {
        int hash[26]={0};
        int l=0;
        int r=0;
        int n=answerkey.size();
        int lenmax=0;
        int maxf=0;
        while(r<n){
            hash[answerkey[r]-'A']++;
            maxf=max(maxf,hash[answerkey[r]-'A']);
            if(r-l+1-maxf>k){
                hash[answerkey[l]-'A']--;
                l++;
            }
            if(r-l+1-maxf<=k){
                lenmax=max(lenmax,r-l+1);
            }
            r++;
        }
        return lenmax;
    }
};