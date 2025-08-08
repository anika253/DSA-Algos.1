#include <iostream>
#include <vector>
using namespace std;

int target; 

// DFS returns the size of the current partial subtree after extracting
// any full components of size >= target.
int dfs(int node, int parent, vector<vector<int>> &g, int &formed) {
    int sz = 1;
    for (int nei : g[node]) {
        if (nei == parent) continue;
        sz += dfs(nei, node, g, formed);
    }
    if (sz >= target) {
        // we can cut here and form a component of size >= target
        formed++;
        return 0; // do not contribute upward
    }
    return sz; // propagate partial size upward
}

bool can(int n, int k, vector<vector<int>> &g, int x) {
    target = x;
    int formed = 0;
    dfs(1, 0, g, formed); // root arbitrarily at 1 (tree is connected)
    // k cuts produce k+1 components
    return formed >= k + 1;
}

int solve_one(int n, int k, vector<vector<int>> &g) {
    int low = 1, high = n, ans = 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (can(n, k, g, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cout << solve_one(n, k, g) << "\n";
    }
    return 0;
}

