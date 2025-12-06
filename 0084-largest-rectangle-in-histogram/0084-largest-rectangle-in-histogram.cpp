class Solution {
public:
vector<int>pse(vector<int>&heights)
{
int n = heights.size();
vector<int>final( n , -1);
stack<int>st;
   for( int i = 0; i<n ; i++)
   {
    while(!st.empty() && heights[i] <= heights[st.top()])
    {
        st.pop();
    }
    if(st.empty())
    {
        final[i]=-1;
    }
    else{
        final[i]= st.top();
    }
    st.push(i);
   }
   return final;
}
vector<int>nse(vector<int>&heights)
{
int n = heights.size();
vector<int>final( n , n);
stack<int>st;
   for( int i = n-1; i>=0 ; i--)
   {
    while(!st.empty() && heights[i] <=heights[st.top()])
    {
        st.pop();
    }
    if(st.empty())
    {
        final[i]=n ;
    }
    else{
        final[i]= st.top();
    }
    st.push(i);
   }
   return final;
}
  
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int>x1 = nse(heights);
        vector<int>x2 = pse(heights);
        int area = INT_MIN;
       for( int i =0 ; i<n ; i++)
       {
        area = max(area , (x1[i]-x2[i]-1)*heights[i]);
       }
       return area;

    }
};