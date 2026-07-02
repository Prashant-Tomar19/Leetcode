class Solution {
public:
    int maxDepth(string s) {
        int maximum=0;
        int curr=0;
        for(int i =0; i<s.size(); i++){
            if(s[i]=='('){
                curr++;
                maximum=max(maximum,curr);
            }
            else if(s[i]==')'){
                curr--;
            }
            else{
                continue;
            }
        }
        return maximum;
    }
};