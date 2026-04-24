// Last updated: 4/24/2026, 10:10:22 PM
class Solution {
public:
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int base = 0;
    for (int i = 0; i < n; i++)
        if (grumpy[i] == 0) base += customers[i];
    int windowGain = 0;
    for (int i = 0; i < minutes; i++)
        if (grumpy[i] == 1) windowGain += customers[i];

    int maxGain = windowGain;
    for (int right = minutes; right < n; right++) {
        int left = right - minutes;  
        if (grumpy[right]) windowGain += customers[right];
        if (grumpy[left])  windowGain -= customers[left];
        maxGain = max(maxGain, windowGain);
    }

    return base + maxGain;
}
};