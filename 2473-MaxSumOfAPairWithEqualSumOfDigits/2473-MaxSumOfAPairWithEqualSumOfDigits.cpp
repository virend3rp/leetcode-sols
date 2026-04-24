// Last updated: 4/24/2026, 10:06:25 PM
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> digitSumMap;
        for (int num : nums) {
            int sum = digitSum(num);
            digitSumMap[sum].push_back(num);
        }

        int maxSum = -1;
        for (auto& entry : digitSumMap) {
            vector<int>& group = entry.second;
            if (group.size() > 1) {
                sort(group.rbegin(), group.rend());
                maxSum = max(maxSum, group[0] + group[1]);
            }
        }

        return maxSum;
    }
};
