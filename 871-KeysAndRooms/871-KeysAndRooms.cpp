// Last updated: 4/24/2026, 10:11:27 PM
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> canVisit(rooms.size(),false);
        vector<int> keys={0};
        canVisit[0]=true;
        while(!keys.empty()){
            int k=keys.back();
            keys.pop_back();
            for(int r:rooms[k]){
                if(!canVisit[r]){
                    keys.push_back(r);
                    canVisit[r]=true;
                }
            }
        }
        for(bool visitable:canVisit){
            if(!visitable){return false;}
        }
        return true;

        

    }
};