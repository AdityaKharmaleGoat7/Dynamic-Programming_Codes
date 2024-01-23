#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, vector<vector<bool>> &dp, int n, int sum) {
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    solve(arr, dp, n, sum);

    int minDiff = INT_MAX;

    for (int i = 0; i <= sum / 2; i++) {
        if (dp[n][i]) {
            int currentDiff = sum - 2 * i;
            minDiff = min(minDiff, abs(currentDiff));
        }
    }

    cout << minDiff << endl;

    return 0;
}
