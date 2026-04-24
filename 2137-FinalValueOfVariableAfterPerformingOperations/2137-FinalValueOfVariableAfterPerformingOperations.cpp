// Last updated: 4/24/2026, 10:07:28 PM
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i][1]=='-'){
                count-=1;
            }
            else{
                count+=1;
            }
        }
        return count;
    }
};