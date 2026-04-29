class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxCount = 0;
        for(int i = 0; i < 26; i++){
            char c = 'A' + i;
            int charCount = 0;
            int nonCharCount = 0;
            int j = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == c){
                    charCount += 1;
                }else{
                    nonCharCount += 1;
                    while(nonCharCount > k){
                        if(s[j] == c){
                            charCount -= 1;
                        }else{
                            nonCharCount -= 1;
                        }
                        j += 1;
                    }
                }
                maxCount = max(maxCount, charCount + nonCharCount);
            }
        }
        return maxCount;
    }
};
