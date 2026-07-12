class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) { // start of a sequence
                int curr = num;
                int length = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    length++;
                }
                maxLen = max(maxLen, length);
            }
        }
        return maxLen;
    }
};