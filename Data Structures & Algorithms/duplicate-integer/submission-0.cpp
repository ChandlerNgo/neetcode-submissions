class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> numbers;
        for(auto x : nums){
            numbers.insert(x);
        }
        return numbers.size() != nums.size();
    }
};