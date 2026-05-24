class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {

            minHeap.push(num);

            // Keep only k largest elements
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Top will be kth largest
        return minHeap.top();
    }
};