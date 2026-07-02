class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        int i= 0;
        for(i= num.length()-1; i>=0; i--){
            if((int)num[i] % 2 != 0){
                break;
            }
            else if(i==0){
                return "";
            }
            else{
                continue;
            }
        }
        for(int j=0; j<=i; j++){
            ans.push_back(num[j]);
        }
        return ans;
    }
};