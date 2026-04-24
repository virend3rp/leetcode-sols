// Last updated: 4/24/2026, 10:04:29 PM
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int count=0;
        int n=message.size();
        int m=bannedWords.size();
        unordered_set<string> banned(bannedWords.begin(),bannedWords.end());
        for(int i=0;i<n;i++){
            if(banned.find(message[i]) != banned.end()){
                count++;
            }
            if(count>=2){
                break;
            }
        }
        if(count>=2){
            return true;
        }
        
        return false;
    }
};