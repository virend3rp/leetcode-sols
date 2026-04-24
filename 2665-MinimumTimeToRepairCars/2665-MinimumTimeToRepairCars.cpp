// Last updated: 4/24/2026, 10:05:46 PM
typedef long long int ll;
class Solution {
    long long tot_cars(long long min, vector<int>& ranks){
        ll cnt = 0;
        for(int i = 0 ; i < ranks.size(); i++){
            cnt += sqrt(min/ranks[i]);
        }
        return cnt;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll low = 1;
        ll high = *max_element(ranks.begin(), ranks.end()) * 1LL * cars * cars;

        while (low <= high) {
            ll mid = (low + high) / 2;
            if (tot_cars(mid, ranks) >= cars)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
