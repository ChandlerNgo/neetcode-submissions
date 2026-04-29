class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // characterSet
        set<char> characterSet;

        for(auto word : words){
            for(auto c : word){
                characterSet.insert(c);
            }
        }
        
        map<char,vector<char>> adj;
        map<char,int> indegrees;
        for(auto c : characterSet){
            indegrees[c] = 0;
        }

        for(int i = 0; i < words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];

            int minLength = min(w1.size(),w2.size());
            bool found = false;
            for(int j = 0; j < minLength; j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].push_back(w2[j]);
                    indegrees[w2[j]] += 1;
                    found = true;
                    break;
                }
            }

            if(!found && w1.size() > w2.size()){
                return "";
            }
        }

        // find first letter that doesnt have any characters pointing into it
        queue<char> q;
        for(auto c : characterSet){
            if(indegrees[c] == 0){
                q.push(c);
            }
        }

        set<char> visited;
        string language = "";

        while(!q.empty()){
        // if a character is completed, then the characters that it points to must -= 1
            char c = q.front();
            q.pop();

            language += c;

            for(auto nextC : adj[c]){
                indegrees[nextC] -= 1;
                if(indegrees[nextC] <= 0){
                    q.push(nextC);
                }
            }
        }

        if(language.size() == characterSet.size()){
            return language;
        }else{
            return "";
        }
    }
};
