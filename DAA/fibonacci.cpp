#include <iostream>
using namespace std;

int steps = 0;

void fibonacci_iterative(int n) {
    int a = 0, b = 1, c;
    int steps = 0;

    for (int i = 0; i < n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
        steps++;
    }

    cout << "\nStep count: " << steps << endl;
}


int fibonacci_recursive(int n) {
    steps++;

    if (n <= 1)
        return n;

    return fibonacci_recursive(n - 1)
         + fibonacci_recursive(n - 2);
}


int main() {
    int n, choice;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "1. Iterative" << endl;
    cout << "2. Recursive" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        fibonacci_iterative(n);
    }
    else if (choice == 2) {
        steps = 0;

        for (int i = 0; i < n; i++)
            cout << fibonacci_recursive(i) << " ";

        cout << "\nStep count: " << steps << endl;
    }
    else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}

// Iterative Fibonacci
// Time Complexity: O(n)
// Space Complexity: O(1)

// Recursive Fibonacci
// Time Complexity: O(2^n) for a single call
// Space Complexity: O(n) due to recursion stack



