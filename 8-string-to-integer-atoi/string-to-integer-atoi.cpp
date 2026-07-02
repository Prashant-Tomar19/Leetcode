class Solution {
public:
    int myAtoi(string s) {
        bool reading=false;
        bool positive=true;
        string ans="";
        for(char ch : s){
            if(reading==false){
                if(isdigit(ch)){
                    reading=true;
                    if(ch!='0'){
                        ans.push_back(ch);
                    }
                    
                }
                else if(ch==' '){
                    continue;
                }
                else if(ch=='-'){
                    positive=false;
                    reading=true;
                }
                else if(ch=='+'){
                    reading=true;
                }
                else{
                    return 0;
                }
                
            }
            else{
                if(isdigit(ch) && ans.size()<=10){
                    if(ch=='0' && ans.size()==0){
                        continue;
                    }
                    else{
                        ans.push_back(ch);
                    }
                    
                }
                else{
                    break;
                }
            }
        
        }
        if(ans==""){
            return 0;
        }
        long long num=stoll(ans);
        if(positive==true && num>INT_MAX){
            return INT_MAX;
        }
        if(positive==false && -(num)<INT_MIN){
            return INT_MIN;
        }
        if(positive==true){
            return num;
        }
        else{
            num =-(num);
            return num;
        }
    }
};