class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {

    int m = r - l + 1;

    vector<long long> up(m, 1), down(m, 1);
    vector<long long> newUp(m), newDown(m);
    vector<long long> prefix(m + 1), suffix(m + 1);

    for (int len = 2; len <= n; len++) {

        fill(newUp.begin(), newUp.end(), 0);
        fill(newDown.begin(), newDown.end(), 0);

        prefix[0] = 0;
        for (int i = 0; i < m; i++)
            prefix[i + 1] = (prefix[i] + up[i]) % MOD;

        for (int i = 0; i < m; i++)
            newDown[i] = prefix[i];

        suffix[m] = 0;
        for (int i = m - 1; i >= 0; i--)
            suffix[i] = (suffix[i + 1] + down[i]) % MOD;

        for (int i = 0; i < m; i++)
            newUp[i] = suffix[i + 1];

        swap(up, newUp);
        swap(down, newDown);
    }
    long long ans = 0;

    for (int i = 0; i < m; i++) {
        ans = (ans + up[i] + down[i]) % MOD;
    }

    return (int)ans;
}
};