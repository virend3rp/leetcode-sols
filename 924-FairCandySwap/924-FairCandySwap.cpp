// Last updated: 4/24/2026, 10:11:13 PM
class Solution {
 public:
  vector<int> fairCandySwap(const vector<int> &me, const vector<int> &you) {
    unordered_set<int> your_set(you.begin(), you.end());
    int give_me = (accumulate(you.begin(), you.end(), 0) -
                   accumulate(me.begin(), me.end(), 0)) / 2;

    auto it = me.begin();
    while (!your_set.count(give_me + *it)) it++;
    return {*it, give_me + *it};
  }
};