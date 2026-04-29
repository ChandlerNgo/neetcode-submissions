class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> charCount;
        map<char,int> sCount;
        for(auto x : t){
            charCount[x] += 1;
        }

        string answer = "";

        int j = 0;
        int bestJ = 0;
        int bestLength = INT_MAX;
        for(int i = 0; i < s.size(); i++){
            sCount[s[i]] += 1;
            while(checkSubstr(sCount, charCount)){
                if(bestLength > i-j+1){
                    bestJ = j;
                    bestLength = i - j + 1;
                }
                sCount[s[j]] -= 1;
                j += 1;
            }
        }

        if(bestLength == INT_MAX){
            return "";
        }else{
            return s.substr(bestJ,bestLength);
        }
    }

    bool checkSubstr(map<char,int> s, map<char,int> t){ // O(26)
        int count = 0;
        for(auto x : t){
            if(s.find(x.first) == s.end()){
                return false;
            }else{
                if(s[x.first] < x.second){
                    return false;
                }
            }
        }
        return true;
    }
};
