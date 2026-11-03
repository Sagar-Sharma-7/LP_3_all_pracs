#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    float weight, profit;
};

bool compare(Item a, Item b) {
    return (a.profit / a.weight) >
           (b.profit / b.weight);
}

void fractionalKnapsack(vector<Item> items, float capacity) {
    sort(items.begin(), items.end(), compare);

    float totalProfit = 0;
    int steps = 0;

    for (int i = 0; i < items.size(); i++) {
        steps++;

        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {

            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else {

            totalProfit += items[i].profit *
                           (capacity / items[i].weight);
            capacity = 0;
        }
    }

    cout << "Maximum profit: " << totalProfit << endl;
    cout << "Step count: " << steps << endl;
}

int main() {
    int n;
    float capacity;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit: ";
        cin >> items[i].weight >> items[i].profit;
    }

    fractionalKnapsack(items, capacity);

    return 0;
}

// Fractional Knapsack using Greedy Approach
// Time Complexity: O(n log n)
// Space Complexity: O(n)