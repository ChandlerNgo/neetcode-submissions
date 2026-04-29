class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> letters;
        int maxCount = 0;
        int j = 0;
        int maxFreq = 0;
        for(int i = 0; i < s.size(); i++){
            letters[s[i]] += 1;

            maxFreq = max(maxFreq, letters[s[i]]);

            while(i-j+1-maxFreq > k){
                letters[s[j]] -= 1;
                j += 1;
            }

            maxCount = max(maxCount, i-j + 1);
        }
        return maxCount;
    }
};
