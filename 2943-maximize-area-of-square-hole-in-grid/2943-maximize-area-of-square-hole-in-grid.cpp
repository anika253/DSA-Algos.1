class Solution {
public:
    int getMaxSide(vector<int>& bars) {
        if (bars.empty()) return 1;

        sort(bars.begin(), bars.end());

        int longest = 1;
        int curr = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            longest = max(longest, curr);
        }

        return longest + 1;
    }

    int maximizeSquareHoleArea(int n, int m,
                               vector<int>& hBars,
                               vector<int>& vBars) {

        int maxH = getMaxSide(hBars);
        int maxV = getMaxSide(vBars);

        int side = min(maxH, maxV);
        return side * side;
    }
};
