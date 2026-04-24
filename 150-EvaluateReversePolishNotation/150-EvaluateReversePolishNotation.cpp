// Last updated: 4/24/2026, 10:15:08 PM
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int val1 = res.top(); res.pop();
                int val2 = res.top(); res.pop();
                if (token == "+") res.push(val2 + val1);
                else if (token == "-") res.push(val2 - val1);
                else if (token == "*") res.push(val2 * val1);
                else if (token == "/") res.push(val2 / val1);  
            } else {
                res.push(stoi(token));  
            }
        }
        
        return res.top();
    }
};
