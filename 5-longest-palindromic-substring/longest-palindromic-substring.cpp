class Solution {
public:
    string longestPalindrome(string s) {
        string odd="";
        for(int i=0;i<s.size();i++){
            odd.push_back('#');
            odd.push_back(s[i]);
        }
        odd.push_back('#');
        int n= odd.size();
        vector<int>P(n,0);
        int right=-1;
        int center=-1;
        int ans = 0;
        int maxi=0;
        for(int i=0; i<odd.size();i++){
            if(i>right){
                int j=1;
                while(i-j >= 0 &&i+j < n &&odd[i-j] == odd[i+j])
                {
                    P[i]++;
                    j++;
                }
                if(P[i]>maxi){
                    ans=i;
                    maxi=P[i];
                }
                if(i + P[i] > right){
                    center = i;
                    right = i + P[i];
                }
            }
            else{
                int mirror = 2*center -i ;
                P[i] = min(P[mirror], right - i);
                int j=1;
                if(P[mirror]>=right-i){
                    while(i + P[i] + j < n &&i - P[i] - j >= 0 && odd[i + P[i] + j] == odd[i - P[i] - j])
                    {
                        P[i]++;
                        j = 1;
                    }
                    
                    if(P[i]>maxi){
                        ans=i;
                        maxi=P[i];
                    }
                    if(i + P[i] > right){
                        center = i;
                        right = i + P[i];
                    }
                }
                else{
                    P[i]=P[mirror];
                }
            }
        }
        int start = (ans - P[ans]) / 2;
        int length = P[ans];
        return s.substr(start,length);
    }
};