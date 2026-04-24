// Last updated: 4/24/2026, 10:07:19 PM
class Solution {
public:
    bool candistribute(vector<int>& quantities,int optimal,int n){
        int numdist=0;
        for(int i=0; i<quantities.size(); ++i){
            numdist += quantities[i]/optimal;
            if(quantities[i]%optimal!=0){
                numdist ++;
            }
        }
        return numdist <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(candistribute(quantities,mid,n)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};