// Last updated: 4/24/2026, 10:05:21 PM
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countLeft=0;
        int countRight=0;
        int countGap=0;
        for (char ch: moves){
            if(ch=='L'){
                countLeft++;
            }
            else if(ch=='R'){
                countRight++;
            }
            else{
                countGap++;
            }
        }
        return abs(countLeft-countRight)+countGap;
    }
};