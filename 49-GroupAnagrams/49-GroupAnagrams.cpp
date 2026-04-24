// Last updated: 4/24/2026, 10:16:45 PM
class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a map to group the anagrams
        map<string, vector<string>> mpp;

        // Iterate over each string in the input vector
        for (auto& str : strs) {
            // Create a copy of the string and sort it
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            
            // Use the sorted string as the key in the map and group the anagrams
            mpp[sorted_str].push_back(str);
        }

        // Prepare the result vector from the map
        vector<vector<string>> result;
        for (auto& entry : mpp) {
            result.push_back(entry.second);
        }

        return result;
    }
};