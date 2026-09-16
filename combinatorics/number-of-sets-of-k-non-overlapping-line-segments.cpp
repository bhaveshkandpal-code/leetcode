class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;
        
        long long ans = 1;
        int N = n + k - 1;
        int R = 2 * k;
        
        for (int i = 1; i <= R; i++) {
            ans = ans * (N - R + i) % MOD;
            ans = ans * modInverse(i, MOD) % MOD;
        }
        
        return ans;
    }
    
    long long modInverse(long long a, long long mod) {
        long long result = 1;
        long long power = mod - 2;
        
        while (power) {
            if (power & 1)
                result = result * a % mod;
            
            a = a * a % mod;
            power >>= 1;
        }
        
        return result;
    }
};