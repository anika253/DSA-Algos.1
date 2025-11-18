class Solution {
public:
vector<int>nse(vector<int>&heights)
{
    stack<int>st;
    int n= heights.size();
    vector<int>final( n, n);
    for( int i = n-1 ; i>=0 ; i--)
    {
        while(!st.empty() && heights[i]<=heights[st.top()])
        {
            st.pop();
        }
       if(st.empty())
       {
        final[i]=n;
       }
       else{
       final[i]= st.top();
       }

 st.push(i);
    }
    return final;
}
vector<int>pse(vector<int>&heights)
{
    int n = heights.size();
    stack<int>st;
    vector<int>final( n, -1);
    for( int i =0 ; i<n;i++)
    {
        while(!st.empty() && heights[i]<=heights[st.top()])
        {
            st.pop();

        }
        if(st.empty())final[i]=-1;
        else{
          final[i]= st.top();
        }
        st.push(i);
    }
    return final;

}
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans1 =nse(heights);
        vector<int>ans2 = pse(heights);
        int ans =0;
        for( int i =0 ; i<n ; i++)
        {
            ans =max( ans ,(ans1[i]-ans2[i]-1)*heights[i]);
        }
        return ans;
    }
};