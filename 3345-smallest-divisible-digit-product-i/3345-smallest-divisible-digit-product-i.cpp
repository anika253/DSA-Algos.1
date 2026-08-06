class Solution {
public:
int pdt(int a)
{
    if(a==0)return 0;
    int final = 0;
    int ans=1;
    while(a!=0)
    {
        final = a%10;
        a/=10;
        ans*=final;


    }
    return ans;
}
    int smallestNumber(int n, int t) 
    {
        if(pdt(n)%t==0)return n;
        for( int num = n; num<=n+10; num++)
        {
            int x = pdt(num);
            if(x%t==0)
            {
                return num;
            }
        }
        
        return -1;
    }
};