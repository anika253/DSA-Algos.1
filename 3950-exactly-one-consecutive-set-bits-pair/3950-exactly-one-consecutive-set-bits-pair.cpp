class Solution {
public:
    bool consecutiveSetBits(int n) {
        int ct = 0;
        int cs = 0;
        while(n>0)
        {
            int bit = n&1;
            if(bit==1)ct++;
            else{
                ct = 0;
            }
            if(ct>=2)cs++;
            n= n>>1;
        }
        return cs==1;


    }
};