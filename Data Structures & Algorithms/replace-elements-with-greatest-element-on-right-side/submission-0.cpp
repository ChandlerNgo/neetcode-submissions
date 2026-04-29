class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> a(arr.size(),-1);
        int curMax = arr[arr.size()-1];

        for(int i = 1; i < arr.size(); i++){
            a[arr.size()-1-i] = curMax;
            curMax = max(curMax, arr[arr.size()-1-i]);
        }

        return a;
    }
};