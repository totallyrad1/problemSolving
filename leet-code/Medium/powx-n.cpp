class Solution {
public:
    double powpow(double x, long long n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        double result = powpow(x , n / 2);
        result *= result;
        if(n % 2)
            result *= x;
        return result;
    }
    double myPow(double x, int n){
        if(n < 0)
            return 1.0f / powpow(x, n * -1.0f);
        return powpow(x, n);
    }
};