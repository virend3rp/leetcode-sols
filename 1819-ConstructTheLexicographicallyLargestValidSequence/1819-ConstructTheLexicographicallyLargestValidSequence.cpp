// Last updated: 4/24/2026, 10:08:22 PM
class Solution {
 public:
    vector<int> constructDistancedSequence(int n) {
        int len = 2 * n - 1;
        ans_.assign(len, 0);
        used_.assign(n + 1, false);

        backtrack(0, n);
        return ans_;
    }

 private:
    vector<int> ans_;
    vector<bool> used_;
    bool found_ = false;

    void backtrack(int pos, int n) {
        if (pos == static_cast<int>(ans_.size())) {
            found_ = true;
            return;
        }

        if (ans_[pos] != 0) {
            backtrack(pos + 1, n);
            return;
        }

        for (int i = n; i >= 1; --i) {
            if (!used_[i]) {
                if (i == 1) {
                    ans_[pos] = 1;
                    used_[1] = true;

                    backtrack(pos + 1, n);
                    if (found_) return;

                    ans_[pos] = 0;
                    used_[1] = false;
                } else {
                    int nextPos = pos + i;
                    if (nextPos < static_cast<int>(ans_.size()) && ans_[nextPos] == 0) {
                        ans_[pos] = i;
                        ans_[nextPos] = i;
                        used_[i] = true;

                        backtrack(pos + 1, n);
                        if (found_) return;

                        ans_[pos] = 0;
                        ans_[nextPos] = 0;
                        used_[i] = false;
                    }
                }
            }
        }
    }
};