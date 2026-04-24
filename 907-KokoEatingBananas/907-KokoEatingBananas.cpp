// Last updated: 4/24/2026, 10:11:18 PM
class Solution {
    bool canEat(vector<int>& piles, int mid, int h){
        int hours = 0;
        for(int i=0; i<piles.size(); ++i){
            hours += piles[i]/mid;
            if(piles[i]%mid!=0){
                hours ++;
            }
        }
        return hours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int hours = 0;
        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        while(l<r){
            int mid = l + (r-l)/2;
            if(canEat(piles, mid, h)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};