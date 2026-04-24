// Last updated: 4/24/2026, 10:17:22 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lefth=0;
        int n=height.size();
        int righth=n-1;
        int ans=0;
        while(lefth<righth){
            int area=abs((righth-lefth)*min(height[righth],height[lefth]));
            ans=max(ans,area);
            if(height[lefth]>height[righth]){
                righth--;
            }
            else{
                lefth++;
            }
        }
        return ans;
    }
};