class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> numbers; // next neede val : seq count

        for(auto x : nums){
            numbers[x+1] = max(numbers[x+1], numbers[x]+1);
            if(numbers.find(x) != numbers.end()){
                numbers[x] -= 1;
                if(numbers[x] == 0){
                    numbers.erase(x);
                }
            }
        }

        int maxLength = 0;

        for(auto x : numbers){
            maxLength = max(maxLength, x.second);
        }
        return maxLength;
    }
};
