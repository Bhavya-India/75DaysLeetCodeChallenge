class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxHeap;

        // Add all stones into max heap
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        // Smash stones until one or none left
        while (maxHeap.size() > 1) {

            int y = maxHeap.top();
            maxHeap.pop();

            int x = maxHeap.top();
            maxHeap.pop();

            // If stones are different
            if (y != x) {
                maxHeap.push(y - x);
            }
        }

        // Return remaining stone or 0
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};