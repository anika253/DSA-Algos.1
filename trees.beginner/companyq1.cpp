#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 1;
const int M = 20;

vector<int> adj[N];
int dep[N], par[N][M];

void dfs(int cur, int parent) {
    dep[cur] = dep[parent] + 1;
    par[cur][0] = parent;
    for (int j = 1; j < M; j++) {
        par[cur][j] = par[par[cur][j - 1]][j - 1];
    }
    for (auto x : adj[cur]) {
        if (x != parent)
            dfs(x, cur);
    }
}

int kthparent(int u, int k) {
    for (int i = M - 1; i >= 0; i--) {
        if ((1 << i) & k) u = par[u][i];
    }
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    dep[0] = -1;
    dfs(1, 0);

    for (int i = 0; i < q; i++) {
        int u, k;
        cin >> u >> k;
        int parent = kthparent(u, k);
        cout << (parent == 0 ? -1 : parent) << "\n";
    }

    return 0;
}
