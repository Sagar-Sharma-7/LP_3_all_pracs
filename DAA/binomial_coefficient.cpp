#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    if (n < 0 || k < 0 || k > n) {
        cout << "Invalid values. Use n >= 0 and 0 <= k <= n.\n";
        return 0;
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    cout << "C(" << n << ", " << k << ") = " << dp[n][k] << "\n";

    return 0;
}
// Binomial Coefficient using Dynamic Programming
// Time Complexity: O(n * k)
// Space Complexity: O(n * k)