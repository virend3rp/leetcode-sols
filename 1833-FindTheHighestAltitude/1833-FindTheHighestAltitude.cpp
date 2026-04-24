// Last updated: 4/24/2026, 10:08:17 PM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt=0;
        int sum=0;
        for(auto& height:gain){
            sum+=height;
            alt=max(alt,sum);
        }
        return alt;
    }
};