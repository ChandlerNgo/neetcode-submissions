class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool answer = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                answer |= dfs(board, word, 0, i, j);
            }
        }
        return answer;
    }

    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j){
        if(index == word.size()){
            return true;
        }

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]){
            return false;
        }

        // backtracking
        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, word, index + 1, i+1, j) || dfs(board, word, index + 1, i-1, j) || dfs(board, word, index + 1, i, j+1) || dfs(board, word, index + 1, i, j-1);

        board[i][j] = temp;

        return found;
    }
};
