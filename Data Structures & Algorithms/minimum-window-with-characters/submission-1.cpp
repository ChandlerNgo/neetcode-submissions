class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> charCount;
        map<char,int> sCount;
        for(auto x : t){
            charCount[x] += 1;
        }

        // count the amount of letters that are in our window

        // compare to the amount in sCount aka sCount.size()

        int bestLeft = -1;
        int bestRight = -1;
        int bestLength = INT_MAX;

        int charLetters = charCount.size();
        int currentLetters = 0; // how many letters match charLetters

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            if(charCount.find(s[right]) != charCount.end()){ // we dont need to add letters we dont care about
                sCount[s[right]] += 1; // add current Letter
                if(sCount[s[right]] == charCount[s[right]]){
                    currentLetters += 1;
                }
            }

            while(currentLetters == charLetters){ // closing window
                if((right - left + 1) < bestLength){
                    bestLeft = left;
                    bestRight = right;
                    bestLength = right - left + 1;
                }

                // adjust our current Letters
                if(charCount.find(s[left]) != charCount.end()){
                    sCount[s[left]] -= 1;
                    if(sCount[s[left]] < charCount[s[left]]){
                        currentLetters -= 1;
                    }
                }

                left += 1;
            }
        }

        if(bestLength == INT_MAX){
            return "";
        }else{
            return s.substr(bestLeft, bestLength);
        }
    }
};
