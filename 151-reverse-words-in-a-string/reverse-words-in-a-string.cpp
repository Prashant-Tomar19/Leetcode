class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        int a=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' ' && word!=""){
                words.push_back(word);
                word="";
                a++;
            }
            else if(s[i]!=' '){
                word.push_back(s[i]);
            }
            else{
                continue;
            }
        }
        if(word != ""){
            words.push_back(word);
        }
        string ans="";
        for(int i = words.size()-1; i >= 0; i--){
            ans.append(words[i]);
            if(i!=0){ans += ' ';}
        }
        return ans;
    }
};