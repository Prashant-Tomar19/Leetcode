class Solution {
public:
    string removeOuterParentheses(string s) {
        int left=0;
        int right=0;
        int remove_index=0;
        for(int i =0; i<s.length(); i++){
            if(s[i]=='('){
                left++;
                if(left==1){
                    remove_index=i;
                }
            }
            else{
                right++;
                
                if(left==right){
                    left=0;
                    right=0;
                    s.erase(remove_index,1);
                    i--;
                    s.erase(i,1);
                    i--;
                    remove_index=i;

                }
            }
        }
        return s;
    }
};