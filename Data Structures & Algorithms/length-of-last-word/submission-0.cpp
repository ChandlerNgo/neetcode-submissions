class Solution {
public:
    int lengthOfLastWord(string s) {
        int maxCount = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i])){
                count += 1;
            }else{
                if(count != 0){
                    maxCount = count;
                }
                count = 0;
            }
        }
        if(count != 0){
            maxCount = count;
        }
        return maxCount;
    }
};