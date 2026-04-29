class Solution {
public:
    int findMin(vector<int> &nums) {
        // 3 cases
        // l < m > r
        // l < m < r
        // l > m < r
        int l = 0;
        int r = nums.size() - 1;

        if(nums.size() == 1){
            return nums[0];
        }

        while(l+1 < r){
            int m = (l+r)/2;
            if(nums[l] <= nums[m] && nums[m] <= nums[r]){
                return nums[l];
            }

            if(nums[l] <= nums[m] && nums[m] >= nums[r]){
                l = m;
            }else if(nums[l] >= nums[m] && nums[m] <= nums[r]){
                r = m;
            }
        }
        return min(nums[l],nums[l+1]);
    }
};
