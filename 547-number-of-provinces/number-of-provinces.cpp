class Solution {
public:
    vector<int> parent;
    vector<int> rnk;

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        rnk.resize(n, 0);
        int provinces = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    if (dounion(i, j))
                        provinces--;
                }
            }
        }
        return provinces;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool dounion(int x, int y) {
        int RootX = find(x);
        int RootY = find(y);
        if (RootX == RootY)
            return false;
        if (rnk[RootX] < rnk[RootY]) {
            parent[RootX] = RootY;
        } else if (rnk[RootY] < rnk[RootX]) {
            parent[RootY] = RootX;
        } else {
            parent[RootY] = RootX;
            rnk[RootX]++;
        }
        return true;
    }
};