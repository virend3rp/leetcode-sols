// Last updated: 4/24/2026, 10:11:25 PM
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        vector<long long > shift(n,0);
        for(int i=0;i<n;i++){
            shift[0]+=shifts[i];
            if(i+1<n){
            shift[i+1]-=shifts[i];
            }
        }
        for(int i=1;i<n;i++){
            shift[i]+=shift[i-1];
        }
        for (int i = 0; i < n; i++) {
            int totalShift = shift[i] % 26;  // Reduce shift to within 0-25 (alphabet range)
            s[i] = (s[i] - 'a' + totalShift) % 26 + 'a';  // Shift the character
        }
        return s;
    }
};