class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> sLetters;
        map<char,int> tLetters;
        for(int i = 0; i < s.size(); i++){
            sLetters[s[i]] += 1;
        }
        for(int i = 0; i < t.size(); i++){
            tLetters[t[i]] += 1;
        }

        return sLetters == tLetters;
    }
};
