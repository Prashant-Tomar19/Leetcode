class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0){
            return true;
        }
        vector<int>arr;
        int top_element=-1;
        for(int i=0; i<s.size();i++){
            if(s[i]=='('){
                arr.push_back('(');
            }
            if(s[i]=='{'){
                arr.push_back('{');
            }
            if(s[i]=='['){
                arr.push_back('[');
            }
            if(arr.size()==0){
                return false;
            }
            if(s[i]==')'){
                if(arr.back()=='('){
                    arr.pop_back();
                }
                else{
                    return false;
                }
            }
            if(s[i]=='}'){
                if(arr.back()=='{'){
                    arr.pop_back();
                }
                else{
                    return false;
                }
            }
            if(s[i]==']'){
                if(arr.back()=='['){
                    arr.pop_back();
                }
                else{
                    return false;
                }
            }
        }
        if(arr.size()==0){
            return true;
        }
        return false;
    }
};