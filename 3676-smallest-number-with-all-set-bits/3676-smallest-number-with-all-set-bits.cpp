class Solution {
public:
    int smallestNumber(int n) {
        long long val = 1;
        while(val <n)
        {
            val = (val<<1)|1;

        }
        return val;
        
    }
};