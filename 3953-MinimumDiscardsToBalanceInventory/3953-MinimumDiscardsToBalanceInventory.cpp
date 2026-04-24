// Last updated: 4/24/2026, 10:03:30 PM
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n=arrivals.size();
        if(n==0) return 0;
        unordered_map<int,int> frequency;
        frequency.reserve(min(n,1000));
        vector<int> kept(n,0);
        int discards=0;
        for(int i=0;i<n;i++){
            int out_idx=i-w;
            if(out_idx>=0 && kept[out_idx]){
                frequency[arrivals[out_idx]]--;
            }

            int typ=arrivals[i];
            if(frequency[typ]<m){
                kept[i]=1;
                frequency[typ]++;
            }
            else{
                kept[i]=0;
                ++discards;
            }
        }
        return discards;
    }
};