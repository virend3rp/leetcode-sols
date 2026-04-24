// Last updated: 4/24/2026, 10:14:26 PM
class Solution {
public:
    string shortestPalindrome(string s) {
        long long m1 = 1e9+9ll;
        long long m2 = 1e9+7ll;
        long long p1 = 31;
        long long p2 = 31;
        int n = s.size();
        long long H1 = 0,H2 = 0;
        int so_far = 0;
        for(int i=0;i<n;i++){
            int a = s[i]-'a'+1;
            H1 = (H1 + (a*p1)%m1 )%m1;
            p1 = p1*31;
            if(p1>m1)p1%=m1;
            
            
            H2 = H2*31;
            if(H2>m1)H2%=m1;
            H2 = (H2 + (a*p2)%m1)%m1;
            //cout<<H1 <<" "<<H2<<endl;
            if(H1 == H2 ){
                so_far = max(so_far,i+1);
            }
            
        }
        string pref ="";
        for(int i=n-1;i>=so_far;i--)pref+=s[i];
        string ans = pref+s;
        return ans;
        
    }
};