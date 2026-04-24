// Last updated: 4/24/2026, 10:06:54 PM
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> odd , even; // declaring two vectors 
        
        for(int i=0; i<n; i++)
        {
        // separately storing the even and odd indices element.
            if(i%2==0) even.push_back(nums[i]);
            else  odd.push_back(nums[i]);
        }
        
        sort(even.begin() , even.end()); // sorting in ascending order
        sort(odd.begin() , odd.end() , greater<int>()); // sorting in descending order
        
        
        int i=0;
        int j=0;
        
        for(int k=0; k<n; k++){
            
            if(k%2==0) nums[k]=even[i++]; // storing at even indices of nums
            else nums[k]=odd[j++]; // storing at odd indices of nums
        }
        
        return nums;
    }
};