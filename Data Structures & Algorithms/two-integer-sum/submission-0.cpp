class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        map<int,int> potentialVals;
        for(int i = 0; i < nums.size(); i++){
            if(potentialVals.find(target-nums[i]) == potentialVals.end()){
                potentialVals[nums[i]] = i;
            }else{
                return {potentialVals[target-nums[i]], i};
            }
        }
        return {0,0};
    }
};
