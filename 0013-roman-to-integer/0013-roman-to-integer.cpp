class Solution {
public:
int helper(char ch)
{
    if(ch=='I')
    {
        return 1;
    }
   else if(ch=='V')
    {
        return 5;
    }
    else if(ch=='X')
    {
        return 10;
    }
    else if(ch=='L')
    {
        return 50;
    }
    else if(ch=='C')
    {
        return 100;
    }
    else if(ch=='D')
    {
        return 500;
    }
    return 1000;
}
    int romanToInt(string s) {
        int n= s.size();
        int sum = 0;
        for( int i = 0 ; i<n-1 ; i++)
        {
            int a = helper(s[i]);
            int b = helper(s[i+1]);
            if(a>=b)
            {
                sum+= a;

            }
            else{
                sum-=a;

            }
        }
        sum+= helper(s[n-1]);
        return sum;

    }
};