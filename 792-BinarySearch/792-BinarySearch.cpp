// Last updated: 4/24/2026, 10:11:40 PM
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int s=0;
        int e=n-1;
        int m=s+(e-s)/2;
        while(s<=e){
            if(arr[m]==target){
                return m;
            }
            if(arr[m]<target){
                s=m+1;
            }
            else{
                e=m-1;
            }
            m=s+(e-s)/2;
        }
        return -1;
        }
};