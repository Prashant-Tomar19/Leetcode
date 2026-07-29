class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int max_count=0;
        int count=0;
        int n =s.size();
        unordered_map<char,int>mp;
        while(right!=n){
            if(mp.find(s[right])==mp.end() ){
                mp[s[right]]=1;
                count++;
                max_count=max(max_count,count);
            }
            else{
                while(mp[s[right]]==1){
                    mp.erase(s[left]);
                    left++;
                }
                mp[s[right]]=1;
                count=right-left+1;
            }
            right++;
        }
        return max_count;
    }
};





                    