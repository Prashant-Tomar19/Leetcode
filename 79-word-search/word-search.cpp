class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool istrue=false;
        for(int i=0;i<board.size();i++){
            for(int j=0; j<board[0].size();j++){
                if(istrue==true){
                    return true;
                }
                if(word[0]==board[i][j]){
                    check(i,j,0,board,word,istrue);
                }
            }
        }
        return istrue;
    }
    void check(int p,int q ,int k,vector<vector<char>> &board,string & word,bool &istrue ){
        if(k==word.size()){
            istrue=true;
            return;
        }
        if(p==board.size() || q==board[0].size()){
            return;
        }
        if(board[p][q]=='#' || board[p][q]!=word[k]){
            return ;
        }
        char ch = board[p][q];
        board[p][q]='#';
        if(p<board.size()){
            check(p+1,q,k+1,board,word,istrue);
        }
        if(p>0){
            check(p-1,q,k+1,board,word,istrue);
        }
        if(q<board[0].size()){
            check(p,q+1,k+1,board,word,istrue);
        }
        if(q>0){
            check(p,q-1,k+1,board,word,istrue);
        }
        board[p][q]=ch;
        
    }
};