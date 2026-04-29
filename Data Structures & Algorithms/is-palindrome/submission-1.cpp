class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        for(auto c : s){
            if(isalpha(c)){
                newS += tolower(c);
            }else if(isdigit(c)){
                newS += c;
            }
        }
        
        s = newS;

        // even aaaa
        // odd aba
        // check n/2 for both sides, and should be palidrome or not
        for(int i = 0; i < s.size()/2; i++){
            // check i, s.size()-1-i
            if(s[i] != s[s.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};
