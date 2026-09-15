class Solution {
public:
    bool isPowerOfFour(int n) {
        
      
        if (n <= 0)
            return false;

        
        if ((n - 1) % 3 == 0)
            return true;

        return false;
    }
};