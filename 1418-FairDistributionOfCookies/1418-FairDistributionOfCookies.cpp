// Last updated: 4/24/2026, 10:09:34 PM
class Solution {
public:
    bool isPossible(int maxcookie,int ind,int k,vector<int>& parts,vector<int>& cookies){
        if(ind==cookies.size()) return true;
        for(int i=0;i<k;i++){
            if(parts[i]+cookies[ind]<=maxcookie){
               parts[i]=parts[i]+cookies[ind];
               if(isPossible(maxcookie,ind+1,k,parts,cookies)) return true;
               parts[i]=parts[i]-cookies[ind];
            }
            if(parts[i]==0) return false;
        }
        return false;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(),cookies.end());
        int n=cookies.size();
        int l=0;
        int r=0;
        for(int i=0;i<cookies.size();i++){
            r+=cookies[i];
        }
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            vector<int> parts(k,0);
            if(isPossible(mid,0,k,parts,cookies)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};