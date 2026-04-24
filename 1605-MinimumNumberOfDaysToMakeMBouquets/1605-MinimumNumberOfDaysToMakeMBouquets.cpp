// Last updated: 4/24/2026, 10:08:55 PM
class Solution {
public:
    bool makeBouquets(vector<int>& bloomDay,int k,int bqreq,int propday ){
        int bouqcount=0,flowercount=0;
        for(auto it:bloomDay){
            if(it<=propday){
                flowercount++;
            }else{
                flowercount=0;
            }
            if(flowercount==k){
                flowercount=0;
                bouqcount++;
            }
        }
        return bouqcount>=bqreq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1;
        int minday=-1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(makeBouquets(bloomDay,k,m,mid)){
                minday =mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return minday;;
    }
};