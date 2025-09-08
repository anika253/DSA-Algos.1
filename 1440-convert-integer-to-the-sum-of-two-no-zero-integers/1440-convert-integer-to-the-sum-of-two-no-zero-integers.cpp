class Solution {
public:
bool hasZero ( int x)
{
    while( x>0)
    {
       if(x%10 ==0)return true;
       x= x/10;

    }
    return false;
}
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i = 1 ; i<= n ; i++)
        {
                if(!hasZero(i) && !hasZero(n-i))
                {
                    ans.push_back(i);
                    ans.push_back(n-i);
                    break;

                }
        }
        return ans;
    }
};