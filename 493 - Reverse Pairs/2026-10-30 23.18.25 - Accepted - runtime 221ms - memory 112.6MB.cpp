#include <vector>

class Solution {
public:
    int reversePairs(std::vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(std::vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);

        // Count valid reverse pairs
        int j = mid + 1;
        for (int i = low; i <= mid; ++i) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Standard merge
        std::vector<int> temp;
        temp.reserve(high - low + 1);
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int k = 0; k < temp.size(); ++k) {
            nums[low + k] = temp[k];
        }

        return count;
    }
};