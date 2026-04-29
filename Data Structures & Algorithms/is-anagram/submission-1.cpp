class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> ss;
        map<char,int> tt;
        
        for(int i = 0; i < s.size(); i++){
            ss[s[i]] += 1;
        }
        for(int i = 0; i < t.size(); i++){
            tt[t[i]] += 1;
        }

        if(ss.size() == tt.size()){
            for(auto x : ss){
                if(tt.find(x.first) == tt.end() or tt[x.first] != ss[x.first]){
                    return false;
                }
            }
        }else{
            return false;
        }

        return true;
    }
};
