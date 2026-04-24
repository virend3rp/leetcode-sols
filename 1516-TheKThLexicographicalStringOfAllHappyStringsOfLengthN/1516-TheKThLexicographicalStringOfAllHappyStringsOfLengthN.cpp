// Last updated: 4/24/2026, 10:09:09 PM
class Solution {
public:
    void happyGenerate(int n, string current, vector<string>& final, const vector<char>& chars) {
        if (current.length() == n) {
            final.push_back(current);
            return;
        }
        for (char c : chars) {  // Now chars is a vector, so range loop works
            if (current.empty() || current.back() != c) {  
                happyGenerate(n, current + c, final, chars);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<char> chars = {'a', 'b', 'c'};  // Use vector instead of raw array
        vector<string> final;
        happyGenerate(n, "", final, chars);
        
        if (k > final.size()) return "";  
        return final[k - 1];
    }
};
