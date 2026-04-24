// Last updated: 4/24/2026, 10:11:41 PM
class KthLargest {
    private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    public:
    // Constructor to initialize the object
    KthLargest(int k, vector<int>& nums) {      
        // Add each element from nums to the heap
        this->k=k;
        for (int num : nums) {
            add(num); // Use the add function to ensure the heap size stays at k
        }
    }
    
    // Add a new value to the stream and return the k-th largest element
    int add(int val) {
        // Push the new value into the min-heap
        minHeap.push(val);
        
        // If the heap size exceeds k, remove the smallest element (top of the min-heap)
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        
        // The k-th largest element is now at the top of the min-heap
        return minHeap.top();
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */