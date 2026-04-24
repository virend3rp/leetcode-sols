// Last updated: 4/24/2026, 10:11:01 PM
class Solution {
public:
// TC : O(N)      S.C : O(1)
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
        for(int i = 0 ; i < s.size() ; i++){
            //openinG 
            if(s[i] == '('){
                st.push(s[i]);
           
            } // closinG
            else{
                if(st.empty()) count++;
                else st.pop();
            }
        }
        return count + st.size() ;
    }
};