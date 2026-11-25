class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        vector<int> nonZero;
        vector<int> zero;

        
        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != 0) {
                nonZero.push_back(nums[i]);
            }
            else {
                zero.push_back(nums[i]);
            }
        }

       
        int k = 0;

        for(int i = 0; i < nonZero.size(); i++) {
            nums[k] = nonZero[i];
            k++;
        }

        
        for(int i = 0; i < zero.size(); i++) {
            nums[k] = zero[i];
            k++;
        }
    }
};