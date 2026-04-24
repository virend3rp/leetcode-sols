// Last updated: 4/24/2026, 10:14:47 PM
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> cur(2*k+1,0);
        vector<int> after(2*k+1,0);
        bool toBuy=1;
        for(int ind=n-1;ind>=0;ind--){
            for(int tranNo=2*k-1;tranNo>=0;tranNo--){
                if(tranNo%2==0 && toBuy){
                        cur[tranNo]=max(-prices[ind]+after[tranNo+1],0+after[tranNo]);
                     }
                 else{
                          cur[tranNo]=max(prices[ind]+after[tranNo+1],0+after[tranNo]);
        }
            after=cur;
            }
        }
        return after[0];   
    }
};