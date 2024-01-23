#include <bits/stdc++.h>
using namespace std;

int solve(int days[], int costs[], int n, int idx) {
    if (idx >= n) {
        return 0;
    }

    int option1 = costs[0] + solve(days, costs, n, idx + 1);
    int option2 = INT_MAX; // Initialize option2 to a large value
    int option3 = INT_MAX; // Initialize option3 to a large value

    int i;
    for (i = idx; i < n && days[i] < days[idx] + 7; i++) {
        // Calculate the total cost for a 7-day pass from this point
        option2 = costs[1] + solve(days, costs, n, i + 1);
    }

    for (i = idx; i < n && days[i] < days[idx] + 30; i++) {
        // Calculate the total cost for a 30-day pass from this point
        option3 = costs[2] + solve(days, costs, n, i + 1);
    }

    // You should calculate the minimum cost among all options
    return min(option1, min(option2, option3));
}

int main() {
    int days[] = {1, 4, 6, 7, 8, 20};
    int n = sizeof(days) / sizeof(int);

    int costs[] = {2, 7, 15};

    cout << solve(days, costs, n, 0);

    return 0;
}
