// Last updated: 4/24/2026, 10:10:41 PM
class Solution {
public:
    int max_el(vector<int>& weights){
        int maxi=0;
        for(int i=0;i<weights.size();i++){
            maxi=max(maxi,weights[i]);
        }
        return maxi;  
    }
    int sum(vector<int>& weights){
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum=sum+weights[i];
        }
        return sum;
    }
    int daysShip(vector<int>& weights,int cap){
        int days=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                days=days+1;
                load=weights[i];
            }
            else{
                load=load+weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=max_el(weights);
        int high=sum(weights);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(daysShip(weights,mid)<=days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};