// Last updated: 4/24/2026, 10:13:30 PM
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};