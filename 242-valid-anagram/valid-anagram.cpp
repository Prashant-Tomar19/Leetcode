class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26]={0};
        if(s.size()!= t.size()){
            return false;
        }
        for(char ch : s){
            freq[ch - 'a']++;
        }
        for(char ch : t){
            freq[ch - 'a']--;
        }
        for(int i=0; i<26; i++){
            if(freq[i]==0){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};