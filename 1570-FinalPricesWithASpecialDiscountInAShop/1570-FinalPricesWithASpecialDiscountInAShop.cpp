// Last updated: 4/24/2026, 10:08:59 PM
class Solution {
public:
    vector<int> smallestRight(vector<int>&prices,int n){
        vector<int> ans(n);
        stack<int> st;

        for (int i = n-1; i>=0; i--) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            
            st.push(prices[i]);
        }
        return ans;
    }
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> discount(n);
        discount=smallestRight(prices,n);
        vector<int>final(n);
        for(int i=0;i<n;i++){
            if(discount[i]==-1){
                final[i]=prices[i];
            }
            else{
                final[i]=prices[i]-discount[i];
            }
        }
        return final;
    }
};