// Last updated: 4/24/2026, 10:16:55 PM
class Solution {
public:
    void subsets(int idx,int target,vector<int>& candidates, vector<vector<int>>& final,vector<int>& ds){
        if(idx==candidates.size()){
            if(target==0){
                final.push_back(ds);
            }
            return;
        }
        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            subsets(idx,target-candidates[idx],candidates,final,ds);
            ds.pop_back();
        }
        subsets(idx+1,target,candidates,final,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> final;
        vector<int> ds;
        subsets(0,target,candidates,final,ds);
        return final; 
    }
};