class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            {return {};}
        vector<string>ans;
        vector<vector<string>>db={{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
        string s="";
        count(0,ans,db,digits,s);
        return ans;
    }
    void count(int i, vector<string> &ans,vector<vector<string>> &db,const string &digits, string &s){
        if(i==digits.size()){
            ans.push_back(s);
            return;
        }
        int index=digits[i]-'2';
        for(int j=0; j<db[index].size(); j++){
            s.push_back(db[index][j][0]);
            count(i+1,ans,db,digits,s);
            s.pop_back();
        }
    }
};