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

        while(l < r){
            int m = (l+r)/2;
            if(nums[m] < nums[r]){
                r = m;
            }else{
                l = m+1;
            }
        }
        return nums[l];
    }
};
