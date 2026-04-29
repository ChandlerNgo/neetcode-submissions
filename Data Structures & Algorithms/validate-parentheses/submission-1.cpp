class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        map<char,char> par;
        par[')'] = '(';
        par[']'] = '[';
        par['}'] = '{';
        for(int i = 0; i < s.size(); i++){
            if(par.find(s[i]) == par.end()){ // opening
                p.push(s[i]);
            }else{
                if(p.empty() || p.top() != par[s[i]]){
                    return false;
                }else{
                    p.pop();
                }
            }
        }

        return p.empty();
    }
};
