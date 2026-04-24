// Last updated: 4/24/2026, 10:16:54 PM
class Solution {
public:
    void subsets(int idx, int target, vector<int>& candidates, vector<vector<int>>& final, vector<int>& ds) {
        if (target == 0) {
            final.push_back(ds);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
            if (candidates[i] > target) break; // If the current candidate exceeds the target, no need to proceed further
            ds.push_back(candidates[i]);
            subsets(i + 1, target - candidates[i], candidates, final, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> final;
        vector<int> ds;
        sort(candidates.begin(), candidates.end()); // Sort the candidates to handle duplicates
        subsets(0, target, candidates, final, ds);
        return final;
    }
};
