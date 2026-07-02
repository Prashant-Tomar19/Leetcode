class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0; i<s.size(); i++){
            int key = s[i];
            if(mp.find(key)==mp.end()){
                mp[key]=1;
            }
            else{
                mp[key]++;
            }
        }
        string ans="";
        vector<pair<char,int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(),
            [](auto &a, auto &b) {
               return a.second > b.second;
            });
        for(auto &p :v){
            int i=0;
            while(i<p.second){
                ans.push_back(p.first);
                i++;
            }
        }
           
        
    return ans;
    }
};