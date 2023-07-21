class Solution {
private:
    double helper(double x, int n){
        if(n == 0)  return 1;
        if(n == 1)  return x;

        if(n%2 == 0){
            double xx = helper(x, n/2);
            return xx*xx;
        }
        else{
            double x1 = helper(x, n/2);
            double x2 = helper(x, n/2+1);
            return x1*x2;
        }
    }
public:
    double myPow(double x, int n) {
        if(x == 1.0)    return x;
        long long newn = n;
        double ans = x;

        if(newn < 0){
            newn = -newn;
        }

        while(newn > 1){
            if(newn%2 == 0){
                x = x*x;
                newn = newn/2;
            }
            else{
                ans = x*ans;
                newn--;
            }
        }

        if(n < 0)   return 1/ans;
        return ans;

        return helper(x, newn);
    }
};
