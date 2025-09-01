class Solution {
public:
    int n;
    
    void dfs(int ind, vector<int>& nums, vector<vector<int>>& final, vector<int>& ds) {
        if (ind == n) {
            if (!ds.empty()) final.push_back(ds); 
            return;
        }
        // take
        ds.push_back(nums[ind]);
        dfs(ind + 1, nums, final, ds);
        ds.pop_back();
        // not take
        dfs(ind + 1, nums, final, ds);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        vector<vector<int>> final;
        sort(nums.begin(), nums.end());
        n = nums.size();

        vector<int> ds;
        dfs(0, nums, final, ds);

        int cnt = 0;
        for (auto& subset : final) {
            bool ok = true;
           
            for (int i = 0; i < subset.size(); i++) {
                for (int j = i + 1; j < subset.size(); j++) {
                    if (abs(subset[i] - subset[j]) == k) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) cnt++;
        }
        return cnt;
    }
};
