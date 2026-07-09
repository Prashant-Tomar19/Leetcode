class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n==1){
            return {{"Q"}};
        }
        if(n==2){
            return {};
        }
        if(n==3){
            return {};
        }
        vector<string> board(n, string(n, '.'));
        vector<vector<string>>ans;
        vector<int> col(n, 0);
        vector<int> diag1(2*n-1, 0); 
        vector<int> diag2(2*n-1, 0);
        
            create(n,board,ans, 0,col,diag1,diag2);
        
        return ans;
    }
    void create(int n, vector<string> &board,vector<vector<string>> &ans,int i,vector<int> &col,vector<int> &diag1, vector<int> &diag2){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int j=0; j<n;j++){

        if(col[j]==0 && diag1[i+j]==0 && diag2[i-j+n-1]==0){
            board[i][j]='Q';
            col[j]=1;
            diag1[i+j]=1;
            diag2[i-j+n-1]=1;
            create(n,board,ans,i+1,col,diag1,diag2);
            board[i][j]='.';
            col[j]=0;
            diag1[i+j]=0;
            diag2[i-j+n-1]=0;
        }
        }

    }
};