class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;
        stack<int> st;

        for (int num : nums2) {

            while (!st.empty() && num > st.top()) {
                mp[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        vector<int> result;

        for (int num : nums1) {

            if (mp.find(num) != mp.end())
                result.push_back(mp[num]);
            else
                result.push_back(-1);
        }

        return result;
    }
};