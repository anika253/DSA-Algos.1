class Solution {
public:
    int candy(vector<int>& ra) {
        int n= ra.size();
        vector<int>l( n , 0);
        vector<int>r( n ,0);
        l[0]= 1;
        for( int i = 1; i<n ; i++)
        {
            if( ra[i]> ra[i-1])
            {
                l[i]= 1+l[i-1];
            }
            else{
                l[i]=1;
            }
        }
        r[n-1]=1;
        for( int i = n-2 ; i>= 0 ; i--)
        {
            if( ra[i]> ra[i+1])
            {
                r[i]= r[i+1]+1;
            }
            else{
                r[i]=1;
            }
        }
    int cnt = 0;
    for( int i = 0 ; i<n ; i++)
    {
        cnt+= max( l[i], r[i]);
    }
    
return cnt;
}
};