class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num=INT_MAX;
        for (int i=1; i<strs.size(); i++){
            int j=0;
            for(j=0; j<strs[i].size(); j++){
                if(strs[i][j]==strs[0][j]){
                    continue;
                }
                else{
                    
                    break;
                }
            }
            num=min(num,j);
        }
        if(num==0){
            return "";
        }
        else{
            return strs[0].substr(0,num);
        }
    }
};