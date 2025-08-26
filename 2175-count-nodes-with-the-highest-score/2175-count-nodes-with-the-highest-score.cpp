class Solution {
public:
    int n;
    vector<int> subtree;
    vector<vector<int>> adj;
    long long maxScore = 0;
    int count = 0;

    int dfs(int node) {
        subtree[node] = 1;
        for (int child : adj[node]) {
            subtree[node] += dfs(child);
        }
        return subtree[node];
    }

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        adj.assign(n, {});
        subtree.assign(n, 0);
        for (int i = 1; i < n; i++) {
            adj[parents[i]].push_back(i);
        }
        dfs(0);
        for (int i = 0; i < n; i++) {
            long long score = 1;
            for (int child : adj[i]) {
                score *= subtree[child];
            }
            if (i != 0) {
                score *= (n - subtree[i]);
            }
            if (score > maxScore) {
                maxScore = score;
                count = 1;
            } else if (score == maxScore) {
                count++;
            }
        }
        return count;
    }
};
