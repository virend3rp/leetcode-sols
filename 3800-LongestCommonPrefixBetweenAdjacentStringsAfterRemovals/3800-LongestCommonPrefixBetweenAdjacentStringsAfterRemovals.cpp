// Last updated: 4/24/2026, 10:03:47 PM
class Solution {
public:
    int commonPrefix(const string& a, const string& b) {
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) return i;
        }
        return len;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        if (n == 1) return {0};

        vector<int> adj(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            adj[i] = commonPrefix(words[i], words[i + 1]);
        }

        vector<int> prefixMax(n - 1), suffixMax(n - 1);
        prefixMax[0] = adj[0];
        for (int i = 1; i < n - 1; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], adj[i]);
        }

        suffixMax[n - 2] = adj[n - 2];
        for (int i = n - 3; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i + 1], adj[i]);
        }

        vector<int> answer(n);
        for (int i = 0; i < n; ++i) {
            int maxPrefix = 0;
            if (i >= 2) maxPrefix = max(maxPrefix, prefixMax[i - 2]);
            if (i < n - 2) maxPrefix = max(maxPrefix, suffixMax[i + 1]);
            if (i > 0 && i < n - 1) {
                maxPrefix = max(maxPrefix, commonPrefix(words[i - 1], words[i + 1]));
            }
            answer[i] = maxPrefix;
        }

        return answer;
    }
};
