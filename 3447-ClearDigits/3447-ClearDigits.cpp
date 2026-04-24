// Last updated: 4/24/2026, 10:04:39 PM
class Solution {
public:
    string clearDigits(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(!isdigit(s[i])){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};