// Last updated: 4/24/2026, 10:05:57 PM
class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int,int> m;
        int ans = 0;
        for(string s:words) {
            int num = 0;
			// compute bitmask
            for(int i:s) num |= (1<<(i-'a'));
			// check if similar string appeared and modify the pair count
            if(m.find(num) != m.end()) ans += m[num];
			// include current bitmask in map
            m[num] += 1;            
        }
        return ans;
    }
};