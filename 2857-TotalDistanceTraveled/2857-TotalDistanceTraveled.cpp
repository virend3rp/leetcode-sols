// Last updated: 4/24/2026, 10:05:27 PM
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        if(mainTank<5){
            return mainTank*10;
        }
        int distance=0;
        while(mainTank){
            distance=distance+10;
            if(distance%50==0){
                if(additionalTank){
                distance=distance+10;
                additionalTank--;
                }
            }
            mainTank--;
        }

        return distance;
    }
};