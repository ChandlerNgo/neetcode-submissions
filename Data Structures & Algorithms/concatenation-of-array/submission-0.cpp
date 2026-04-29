class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> v;
        for(auto x : nums){
            v.push_back(x);
        }
        for(auto x : nums){
            v.push_back(x);
        }
        return v;
    }
};