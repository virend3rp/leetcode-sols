// Last updated: 4/24/2026, 10:03:37 PM
class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        vector<string> segments;
        string current="";
        for(char c : s){
            current+=c;
            if(seen.find(current)==seen.end()){
                segments.push_back(current);
                seen.insert(current);
                current = "";
            }
        }
        
        if(!current.empty()){
            if(seen.find(current)==seen.end()){
                segments.push_back(current);
            }
        }

        return segments;
    }
};