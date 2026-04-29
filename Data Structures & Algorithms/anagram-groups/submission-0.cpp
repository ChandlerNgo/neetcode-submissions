class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> words;
        
        for(auto x : strs){
            map<char,int> word;
            for(auto y : x){
                word[y] += 1;
            }
            words[word].push_back(x);
        }

        vector<vector<string>> answer;

        for(auto x : words){
            answer.push_back(x.second);
        }

        return answer;
    }
};
