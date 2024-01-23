#include <bits/stdc++.h>
using namespace std;

int MinCost(int arr[][3], int m, int n, int i, int j, vector<vector<int>> &dp) { // Specify the size of the second dimension

    if (i == 0 && j == 0) {
        return arr[0][0];
    }
    if (i < 0  ||  j < 0) {
        return 10e6;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int up = arr[i][j] + MinCost(arr, m, n, i - 1, j, dp);
    int left = arr[i][j] + MinCost(arr, m, n, i, j - 1, dp);

    return dp[i][j] = min(up, left);
}

int main() {

    int m = 3, n = 3;

    int arr[3][3] = {{1, 3, 2},
                     {4, 3, 1},
                     {5, 6, 1}};

    int i = m - 1, j = n - 1;
    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << MinCost(arr, m, n, i, j, dp);

    return 0;
}
