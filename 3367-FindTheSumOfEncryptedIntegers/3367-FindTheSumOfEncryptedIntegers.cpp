// Last updated: 4/24/2026, 10:04:50 PM
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
    int sum=0;
    for (auto i: nums){ 
        int max=0;
        int temp=i;
        while(i>0){
            int rem=i%10;
            if(rem>max){
                max=rem;
            }
            i/=10;
        }
        size_t n= to_string(temp).length();
        string v(n,'1');
        int k= stoi(v);
        int t=max*k;
        sum += t;
    }
    return sum;
    };
};