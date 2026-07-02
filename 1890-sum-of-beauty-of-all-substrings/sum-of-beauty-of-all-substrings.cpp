class Solution {
public:
    int beautySum(string s) {
        int total=0;
        for(int i=0; i<s.size();i++ ){
            vector<int> freq(26, 0);
            for(int j=i; j<s.size(); j++){
                freq[s[j]-'a']++;
            int mini=INT_MAX;
            int maxi=0;
            for(int k=0; k<26; k++){
                if(freq[k]<mini && freq[k]>0){
                    mini=freq[k];
                }
                if(freq[k]>maxi){
                    maxi=freq[k];
                }
                else{
                    continue;
                }
            }
            int count=maxi-mini;
            total+=count;
            }
        }
        return total;
    }
};