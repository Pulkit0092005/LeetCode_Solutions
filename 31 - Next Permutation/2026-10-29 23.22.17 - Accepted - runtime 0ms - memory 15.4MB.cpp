
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Step 1: Find the breaking point
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // Step 2: If no breaking point, reverse entire array
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the next greater element from right
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // Step 4: Reverse the remaining suffix
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
