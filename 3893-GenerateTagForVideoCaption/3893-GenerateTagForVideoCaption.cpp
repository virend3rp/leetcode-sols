// Last updated: 4/24/2026, 10:03:39 PM
class Solution {
public:
    string generateTag(const string& caption) {
        stringstream ss(caption);
        string word, result = "#";
        bool firstWord = true;
    
        for (string w; ss >> w;) {
            string cleaned = "";
            
            for (char ch : w) {
                if (isalpha(ch)) cleaned += ch;
            }
    
            if (cleaned.empty()) continue;
            
            for (int i = 0; i < cleaned.size(); ++i) {
                if (firstWord)
                    cleaned[i] = tolower(cleaned[i]);
                else if (i == 0)
                    cleaned[i] = toupper(cleaned[i]);
                else
                    cleaned[i] = tolower(cleaned[i]);
            }
    
            result += cleaned;
            firstWord = false;
            if (result.size() >= 100) break;
        }
    
        if (result.size() > 100) result = result.substr(0, 100);
        return result;
    }
};