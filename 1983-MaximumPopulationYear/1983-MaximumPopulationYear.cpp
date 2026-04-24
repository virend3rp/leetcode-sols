// Last updated: 4/24/2026, 10:07:53 PM
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(101);
        for(auto x:logs){
            int birth = x[0]-1950;
            int end = x[1]-1950;
            diff[birth] +=1;
            diff[end]-=1;
        }
        partial_sum(diff.begin(),diff.end(),diff.begin());
        int maxi = INT_MIN;
        int maxiyear = 1950;
        for(int i=0;i<101;i++){
            if(diff[i] > maxi){
                maxiyear = 1950+i;
                maxi = diff[i];
            }
        }
        return maxiyear;
    }
};