#include <bits/stdc++.h>
using namespace std;

int queens[8];

bool isSafe(int row, int column) {

    for (int previousRow = 0; previousRow < row; previousRow++) {
        int previousColumn = queens[previousRow];

        if (previousColumn == column) {
            return false;
        }

        if (abs(previousColumn - column) == abs(previousRow - row)) {
            return false;
        }
    }
    return true;
}

bool solve(int row) {
    if (row == 8) {
        return true;
    }

    for (int column = 0; column < 8; column++) {
        if (isSafe(row, column)) {
            queens[row] = column;
            if (solve(row + 1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int firstColumn;
    cout << "Enter the first queen's column (1-8): ";
    cin >> firstColumn;

    if (firstColumn < 1 || firstColumn > 8) {
        cout << "Please enter a column from 1 to 8.\n";
        return 0;
    }

    queens[0] = firstColumn - 1;

    if (solve(1)) {
        cout << "8-Queens matrix:\n";
        for (int row = 0; row < 8; row++) {
            for (int column = 0; column < 8; column++) {
                if (queens[row] == column) {
                    cout << "1 ";
                } else {
                    cout << "0 ";
                }
            }
            cout << "\n";
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}

// 8-Queens Problem using Backtracking
// Time Complexity: O(N!)
// Space Complexity: O(N); N = 8 in this implementation
