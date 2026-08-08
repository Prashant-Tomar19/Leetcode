class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int>need;
        unordered_map<int,int>window;
        int best_start=0;
        int best_length=INT_MAX;
        for(int i =0; i<t.size(); i++){
            need[t[i]]++;
        }
        int left=0;
        int have=0;
        int required=need.size();
        for(int i=0; i<s.size(); i++){
            window[s[i]]++;
            if(need.count(s[i]) && window[s[i]]==need[s[i]]){
                have++;
            }
            while(have==required){
                if(i-left+1<best_length){
                    best_length=i-left+1;
                    best_start=left;
                }
                window[s[left]]--;
                if(window[s[left]]<need[s[left]]){
                    have--;
                }
                left++;
            }
            
        }
        if (best_length== INT_MAX)
            return "";

        return s.substr(best_start, best_length);
    }
};