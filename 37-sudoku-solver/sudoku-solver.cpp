class Solution {
public:
    bool solveSudoku(vector<vector<char>>& board) {
        bool isfull=true;
        for(int i=0; i<9;i++){
            for(int j=0; j<9;j++){
                if(board[i][j]=='.'){
                    isfull=false;
                    for(int k=1;k<10;k++){
                        if(is_safe(board,i,j,k)){
                            board[i][j]=k+'0';
                            if(solveSudoku(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        if(isfull){
            return true;
        }
        return false;
    }
    bool is_safe(vector<vector<char>> &board,int row,int col,int digit){
        for(int p=0; p<9;p++){
            if(board[row][p]==digit+'0' || board[p][col]==digit+'0'){
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for(int p=startRow;p<startRow+3;p++){
            for(int q=startCol;q<startCol+3;q++){
                if(board[p][q]==digit+'0'){
                    return false;
                }
            }
        }
        return true;
    }
};