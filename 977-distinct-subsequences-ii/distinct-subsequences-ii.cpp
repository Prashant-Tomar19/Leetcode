class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1000000007;

        int total = 0;
        int neww = 0;
        int freq[26] = {0};

        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i]-'a'] == 0) {
                if(i == 0) {
                    total = 1;
                    freq[s[i]-'a'] = 1;
                }
                else {
                    neww = (total + 1) % MOD;
                    total = (total + neww) % MOD;
                    freq[s[i]-'a'] = neww;
                }
            }
            else {
                neww = ( (total - freq[s[i]-'a'] + 1) % MOD + MOD ) % MOD;
                total = (total + neww) % MOD;
                freq[s[i]-'a'] = (freq[s[i]-'a'] + neww) % MOD;
            }
        }

        return total;
    }
};