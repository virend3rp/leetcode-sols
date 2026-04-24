// Last updated: 4/24/2026, 10:04:52 PM
class Solution {
public:
    int minimumDeletions(string word, int k) {
    unordered_map<char, int> freqMap;
    for (char ch : word) freqMap[ch]++;

    vector<int> freqs;
    for (auto& [_, freq] : freqMap) freqs.push_back(freq);
    sort(freqs.begin(), freqs.end());

    int minDel = INT_MAX;

    for (int base : freqs) {
        int deletions = 0;
        for (int f : freqs) {
            if (f > base + k)
                deletions += f - (base + k);
            else if (f < base)
                deletions += f;
        }
        minDel = min(minDel, deletions);
    }

    return minDel;
    }
};