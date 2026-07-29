class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int maxfreq=0;
        int max_count=0;
        int n= s.size();
        unordered_map<char,int>mp;
        while(right<n){
           mp[s[right]]++;
           maxfreq=max(maxfreq,mp[s[right]]);
            while((right-left+1)-maxfreq>k){
                mp[s[left]]--;
                left++;
            }
            max_count = max(max_count, right - left + 1);
            right++;

        }
        return max_count;
    }
};