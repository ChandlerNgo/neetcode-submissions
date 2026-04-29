class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l < r){
            int m = (l+r)/2;
            if(nums[m] < nums[r]){
                r = m;
            }else{
                l = m+1;
            }
        }

        // l is the minimum value, r is l+nums.size()
        r = l + nums.size()-1;

        while(l <= r){
            int m = (l+r)/2;
            // 4 10 7
            if(nums[m%nums.size()] < target){
                l = m+1;
            }else if(nums[m%nums.size()] > target){
                r = m-1;
            }else{
                return m%nums.size();
            }
        }

        return -1;
    }
};
