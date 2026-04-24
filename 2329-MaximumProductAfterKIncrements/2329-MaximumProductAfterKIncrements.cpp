// Last updated: 4/24/2026, 10:06:46 PM
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    
    int maximumProduct(vector<int>& nums, int k) {
        // Min-heap (priority queue) to store the numbers
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Push all elements from nums into the priority queue
        for (int num : nums) {
            pq.push(num);
        }
        
        // Increment the smallest element k times
        while (k > 0) {
            int top = pq.top();
            pq.pop();
            top++;  // Increment the smallest element
            pq.push(top);  // Push the incremented value back into the heap
            k--;  // Decrease k after each increment
        }
        
        // Calculate the product of all elements in the heap, modulo mod
        long long product = 1;  // Use long long to handle large products
        while (!pq.empty()) {
            product = (product * pq.top()) % mod;  // Apply modulo at each step
            pq.pop();
        }
        
        return product;  // No need for another modulo here
    }
};
