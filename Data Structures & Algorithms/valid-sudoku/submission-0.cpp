#include <unordered_set>

class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        int id = 0;
        unordered_set<int> rows[9];
        unordered_set<int> cols[9];
        unordered_set<int> boxs[3][3];

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    bool a = rows[i].insert(board[i][j]).second;
                    bool b = cols[j].insert(board[i][j]).second;
                    bool c = boxs[i/3][j/3].insert(board[i][j]).second;
                    if (!a or !b or !c){
                        return false;
                    }
                }                
            }
        }
        return true;
    }
};
