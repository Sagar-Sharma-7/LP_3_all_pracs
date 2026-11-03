
#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(Job jobs[], int n) {
    sort(jobs, jobs + n, compare);

    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    char slots[maxDeadline];
    bool filled[maxDeadline] = {false};

    int totalProfit = 0;
    int steps = 0;

    for (int i = 0; i < n; i++) {
        steps++;

        for (int j = min(jobs[i].deadline, maxDeadline) - 1; j >= 0; j--) {
            steps++;

            if (!filled[j]) {
                slots[j] = jobs[i].id;
                filled[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "\nJob sequence: ";

    for (int i = 0; i < maxDeadline; i++) {
        if (filled[i]) {
            cout << slots[i] << " ";
        }
    }

    cout << "\nTotal profit: " << totalProfit;
    cout << "\nStep count: " << steps << endl;
}

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter job ID, deadline and profit: ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobSequencing(jobs, n);

    return 0;
}

// Job Sequencing using Greedy Approach
// Time Complexity: O(n log n + n * d)
// Space Complexity: O(d)
//n = Number of jobs.
//d = Maximum deadline among all jobs.
