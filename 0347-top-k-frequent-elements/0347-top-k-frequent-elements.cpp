class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>a;
        unordered_map<int, int>mpp;
        for(auto it: nums)
        {
            mpp[it]++;
        }
        priority_queue<pair<int , int>>pq;
        for(auto it: mpp)
        {
            pq.push({it.second , it.first});
        }
        while(k)
        {
            a.push_back(pq.top().second);
            pq.pop();
            k--;

        }
        return a;
    }
};