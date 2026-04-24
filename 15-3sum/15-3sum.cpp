// Last updated: 4/24/2026, 10:17:17 PM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> output;

        for(int i = 0; i < n-1; i++){
            int low = i+1;
            int high = n-1;

            while(low < high){
                if(nums[i] + nums[low] + nums[high] < 0){
                    low++;
                } else if(nums[i] + nums[low] + nums[high] > 0){
                    high--;
                } else {
                    output.push_back({nums[i], nums[low], nums[high]});
                    int tempLow = low;
                    int tempHigh = high;

                    while(low < high && nums[low] == nums[tempLow])
                        low++;

                    while(low < high && nums[high] == nums[tempHigh])
                        high--;
                }
            }

            while(i+1 < n && nums[i] == nums[i+1])
                i++;
        }

        return output;
    }
};