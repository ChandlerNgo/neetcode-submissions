class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> results;
        dfs(results, candidates, {}, 0, 0, target);
        vector<vector<int>> answer;
        for(auto x : results){
            answer.push_back(x);
        }
        return answer;
    }

    void dfs(set<vector<int>>& results, vector<int>& candidates, vector<int> current, int index, int sum, int target){
        if(sum > target){
            return;
        }

        if(index == candidates.size()){
            if(sum == target){
                results.insert(current);
            }
            return;
        }

        // skip
        dfs(results, candidates, current, index + 1, sum, target);
        // use the current index
        current.push_back(candidates[index]);
        dfs(results, candidates, current, index, sum + candidates[index], target);
        // use the current index and move to next
        dfs(results, candidates, current, index + 1, sum + candidates[index], target);
    }

};