// Last updated: 4/24/2026, 10:15:03 PM
class Solution {
public:
    int findMin(vector<int>& arr) {
        if(arr.size()==1){
            return arr[0];
        }
        int low=0;
        int high=arr.size()-1;
        int ans=INT_MAX;
        while(low<=high){
           int mid=(low+high)/2;
           if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                 ans=min(ans,arr[low]);
                 low=low+1;
                 high=high-1;
                 continue;
           }
           if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;
           }
           else{
            ans=min(ans,arr[mid]);
            high=mid-1;
           }
        }
        return ans;        
    }
};