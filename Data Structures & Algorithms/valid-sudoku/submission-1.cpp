class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> rows;
        vector<char> columns;
        unordered_map<int, vector<char>> box;

        for(int i = 0; i<9; i++){
            rows.clear();
            columns.clear();
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.'){
                    rows.push_back(board[i][j]);
                    box[((i/3)*3)+(j/3)].push_back(board[i][j]);
                }
                if(board[j][i]!='.'){
                    columns.push_back(board[j][i]);
                }
            }
            set<char> s(rows.begin(), rows.end());
            if(rows.size() != s.size()){
                return false;
            }
            set<char> b(columns.begin(), columns.end());
            if(columns.size() != b.size()){
                return false;
            }
        }
        for(int i = 0; i <9; i++){
            set<char> x(box[i].begin(), box[i].end());
            if(box[i].size() != x.size()){
                return false;
            }
        }
        return true;
    }
};
