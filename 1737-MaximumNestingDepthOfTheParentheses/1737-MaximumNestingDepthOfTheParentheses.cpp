// Last updated: 4/24/2026, 10:08:34 PM
class Solution {
public:
    int maxDepth(string s) {
        int balance=0;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                balance++;
            }
            else if(s[i]==')'){
                if(maxi<balance){
                    maxi=balance;
                }
                balance--;
            }
        }
        return maxi;
    }
};