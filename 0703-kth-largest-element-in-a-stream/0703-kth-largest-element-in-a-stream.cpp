#include <bits/stdc++.h>

using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;//  saves incoming k value into the class so that other methods can remember it 
        // Feed all initial numbers into the heap using our add function
        for (int num : nums) {
           add(num);
        }
    }
    
     int add(int val) {
        //  Push the new value into the min-heap
        minHeap.push(val); 
        
        //  If the heap size exceeds k, remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        
        //  Return the Kth largest element (sitting at the root)
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * Param_1 = obj->add(val);
 */