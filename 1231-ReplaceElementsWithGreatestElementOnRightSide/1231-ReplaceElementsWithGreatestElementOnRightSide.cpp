// Last updated: 4/24/2026, 10:10:06 PM
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int right=arr.size()-1;
        int maxi=-1;
        while(right>=0){
            int temp=arr[right];
            arr[right]=maxi;
            maxi=max(maxi,temp);
            right--;
        }
        return arr;
    }
};