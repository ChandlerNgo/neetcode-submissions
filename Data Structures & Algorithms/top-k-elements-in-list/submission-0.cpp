class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> frequency;
        map<int,int> numbers;
        // sort count into numbers
        for(auto x : nums){
            numbers[x] += 1;
        }
        // add the value into the frequency
        for(auto x : numbers){
            frequency.push({x.second,x.first});
        }
        // pop the top most k values
        vector<int> answer;
        for(int i = 0; i < k; i++){
            answer.push_back(frequency.top().second);
            frequency.pop();
        }
        return answer;
    }
};
