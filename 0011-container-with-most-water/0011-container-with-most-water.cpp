class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int area = INT_MIN;
        while(i<=j)
        {
            int ht = min( height[i], height[j]);
            int my_area = ht*(j-i);
            area = max(area , my_area);
            if(height[i]> height[j])
            {
                j--;
            }
            else{
                i++;
            }
        }
        return area;

    }
};