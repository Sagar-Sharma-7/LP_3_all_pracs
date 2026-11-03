#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int> weights, vector<int> profits,
             int capacity) {
    int n = weights.size();

    vector<vector<int>> dp(
        n + 1, vector<int>(capacity + 1, 0)
    );

    int steps = 0;

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            steps++;

            if (weights[i - 1] <= w) {
                dp[i][w] = max(
                    profits[i - 1] +
                    dp[i - 1][w - weights[i - 1]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum profit: "
         << dp[n][capacity] << endl;

    cout << "Step count: " << steps << endl;

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> profits(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit: ";
        cin >> weights[i] >> profits[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    knapsack(weights, profits, capacity);

    return 0;
}

// 0/1 Knapsack using Dynamic Programming
// Time Complexity: O(n * W); n = number of items, W = knapsack capacity
// Space Complexity: O(n * W)
