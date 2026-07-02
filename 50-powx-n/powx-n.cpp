class Solution {
public:
    double myPow(double x, int n) {
        if(x==0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        double ans=1;
        double y = x;
        if(n<0){
            long long k=static_cast<long long>(n);
            k=(-k);
            while(k>0){
                if(k%2==1){
                    ans*=y;
                }
                y*=y;
                k=k/2;
            }
            return 1/ans;
        }
        while(n>0){
            if(n%2==1){
                ans*=y;
            }
            y*=y;
            n=n/2;
        }
        return ans;
    }
};