class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        vector<int> unique;

        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] != nums[i - 1]) {
                unique.push_back(nums[i]);
            }
        }

        for(int i = 0; i < unique.size(); i++) {
            nums[i] = unique[i];
        }

        return unique.size();
    }
};