// Last updated: 4/24/2026, 10:15:30 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if (nums.empty()) return 0;

        // sort(nums.begin(), nums.end());

        // int n = nums.size();
        // int cnt = 1;  // Start with 1 to count the current number
        // int maxi = 1;  // The minimum sequence length is 1

        // for (int i = 1; i < n; i++) {
        //     if (nums[i] == nums[i - 1]) {
        //         // Skip duplicates
        //         continue;
        //     } else if (nums[i] == nums[i - 1] + 1) {
        //         cnt++;
        //     } else {
        //         cnt = 1;
        //     }
        //     maxi =max(maxi, cnt);
        // }

        // return maxi;
        int n=nums.size();
        if (nums.empty()) return 0;
        int longest=1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt=cnt+1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};