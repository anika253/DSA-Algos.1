class Solution {
public:
const int mod = 1e9+7;
vector<int>pseeh( vector<int>&arr)
{
    stack<int>st;
    vector<int>ans(arr.size(), -1);
    for( int i = 0 ; i<arr.size(); i++)
    {
        while(!st.empty() && arr[st.top()]> arr[i])
        {
          st.pop();
        }
        if(st.empty())
        {
            ans[i]= -1;
        }
        else{
            ans[i]= st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int>nseh( vector<int>&arr)
{
    int n= arr.size();
    vector<int>ans2(n , 0);
    stack<int>st;
    for( int i = n-1 ; i>=0 ; i--)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            ans2[i]= n;
        }
        else{
            ans2[i]= st.top();
        }
        st.push(i);

    }
    return ans2;
}


    int sumSubarrayMins(vector<int>& arr) {
        
     vector<int>psee= pseeh(arr);
     vector<int>nse = nseh(arr);
     long long cnt = 0;
     for( int i = 0 ; i<arr.size(); i++)
     {
      int ns = nse[i]- i;
      int ps= i- psee[i];
      long long ways = 1LL*ns*ps*arr[i];
      cnt= (cnt+ways)%mod;

     }



return cnt;

    }
};