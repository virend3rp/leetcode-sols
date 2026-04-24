// Last updated: 4/24/2026, 10:07:18 PM
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left=0;
        int right=colors.size()-1;
        int diff=-1;
        for(int i=1;i<=right;i++){
            if(colors[left]!=colors[i]){
                diff=max(diff,i-left);
            }
        }
        for(int i=right;i>=left;i--){
            if(colors[right]!=colors[i]){
                diff=max(diff,right-i);
            }
        }
        return diff;
    }
};