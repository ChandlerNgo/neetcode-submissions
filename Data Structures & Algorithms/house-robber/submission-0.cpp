class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);

        return dp(nums, memo, 0);
    }

    int dp(vector<int>& nums, vector<int>& memo, int index){
        if(index >= nums.size()){
            return 0;
        }

        if(memo[index] >= 0){
            return memo[index];
        }

        int result = max(dp(nums, memo, index+1), dp(nums, memo, index+2) + nums[index]);
        memo[index] = result;
        return memo[index];
    }
};
