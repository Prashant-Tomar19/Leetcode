class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_set<char>st;
        unordered_map<int,int>mp;
        int dup=0;
        for(int i=0; i<s.size(); i++){
            int key=s[i];
            char value=t[i];
            st.insert(value);
            int j = st.size();
            
            if(mp.find(key)!=mp.end()){
                if(mp[key]==value){
                    dup++;
                }
                else{
                    return false;
                }
               
            }
            else{
                if(j!=(i-dup+1)){
                        return false;
                    }
                mp[key]=t[i];
                
            }
        }
        return true;
    }
};