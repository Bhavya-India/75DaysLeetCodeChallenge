class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        // Count frequency of tasks
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Find maximum frequency
        int maxFreq = *max_element(freq.begin(), freq.end());

        // Count how many tasks have max frequency
        int maxCount = 0;

        for (int f : freq) {
            if (f == maxFreq) {
                maxCount++;
            }
        }

        // Calculate minimum intervals
        int partCount = maxFreq - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - (maxFreq * maxCount);
        int idles = max(0, emptySlots - availableTasks);

        return tasks.size() + idles;
    }
};