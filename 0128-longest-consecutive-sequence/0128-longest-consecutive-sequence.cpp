class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            // Check if it's the start of a sequence
            if (s.find(num - 1) == s.end()) {
                int current = num;
                int count = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};