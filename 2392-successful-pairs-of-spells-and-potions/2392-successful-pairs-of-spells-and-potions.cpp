class Solution {
public:
int binaryS(int start , int end , vector<int>& p, long long target )
{
  int ind = -1;

 int l = start;
 int r = end;

while(l<=r)
{
    int mid = l+(r-l)/2;
    if(p[mid]>= target)
    {
        ind = mid;
        r = mid-1;
    }
    else{
        l= mid+1;
    }

}
return ind;


}
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        int n = s.size();
        int m = p.size();
        sort(p.begin(), p.end());
        int maxP = p[m-1];
        vector<int>final;
        
        for(int i = 0 ; i<n ; i++)
        {
         int spell = s[i];
         int maxP = p[m-1];
         long long minP = ceil((1.0*success)/spell);
           if(minP> maxP)
           {
            final.push_back(0);
            continue;

           }
           int idx = binaryS(0 , m-1 , p, minP);
           int cnt = m-(idx);
           final.push_back(cnt);



        }
        return final;

    }
};