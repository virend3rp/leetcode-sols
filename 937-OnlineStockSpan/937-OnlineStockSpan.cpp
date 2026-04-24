// Last updated: 4/24/2026, 10:11:10 PM
class StockSpanner {
public:
    stack<pair<int,int>> st; // stack stores pairs of {price, index}
    int ind;
    
    StockSpanner() {
        ind = -1;
        while (!st.empty()) st.pop(); // Clear the stack
    }
    
    int next(int price) {
        ind++;
        
        // Pop elements from the stack while the top price is less than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        
        // Calculate the span
        int ans = st.empty() ? ind + 1 : ind - st.top().second;
        
        // Push the current price and its index onto the stack
        st.push({price, ind});
        
        return ans;
    }
};
