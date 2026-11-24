class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        // Store all elements
        for(int num : nums) {
            st.insert(num);
        }

        int longest = 0;

        for(int num : st) {

            // Check starting point
            if(st.find(num - 1) == st.end()) {

                int count = 1;
                int x = num;

                // Find consecutive numbers
                while(st.find(x + 1) != st.end()) {
                    x++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};