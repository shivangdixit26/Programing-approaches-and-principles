class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        vector<vector<long long>> result = {{1, 0}, {0, 1}};
        vector<vector<long long>> base = {{1, 1}, {1, 0}};
        int exp = n;
        while (exp > 0) {
            if (exp & 1) {
                result = multiply(result, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }
        return (int) result[0][1];
    }

    vector<vector<long long>> multiply(vector<vector<long long>>& a,
                                       vector<vector<long long>>& b) {
        return {
            {a[0][0] * b[0][0] + a[0][1] * b[1][0],
             a[0][0] * b[0][1] + a[0][1] * b[1][1]},
            {a[1][0] * b[0][0] + a[1][1] * b[1][0],
             a[1][0] * b[0][1] + a[1][1] * b[1][1]}
        };
    }
};