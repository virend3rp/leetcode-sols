// Last updated: 4/24/2026, 10:04:48 PM
class Solution {
public:
bool is_prime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}
    int maximumPrimeDifference(vector<int>& nums) {
        int maxIndex=INT_MIN;
        int minIndex=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(is_prime(nums[i])){
                maxIndex=max(maxIndex,i);
                minIndex=min(minIndex,i);
            }
        }
        return maxIndex-minIndex;
    }
};