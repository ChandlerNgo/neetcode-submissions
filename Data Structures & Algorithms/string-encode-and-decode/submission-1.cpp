class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";

        for(auto x : strs){
            encodedString += (to_string(x.size()) + '#' + x);
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedString;
        int num = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '#'){
                num = num*10 + (s[i]-'0');
            }else{
                decodedString.push_back(s.substr(i+1,num));
                i += num;
                num = 0;
            }
        }
        return decodedString;
    }
};
