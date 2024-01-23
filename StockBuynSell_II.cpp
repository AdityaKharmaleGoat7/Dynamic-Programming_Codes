#include <bits/stdc++.h>
using namespace std;

int solveMem(int arr[], int n, int buy, int idx, vector<vector<int>> &dp){

if(idx == n){
    return 0;
}
if(dp[buy][idx] != -1){
    return dp[buy][idx];
}
int profit = 0;

if(buy == 1){
    int buyIt = -arr[idx] + solveMem(arr,n, 0, idx+1, dp);
    int skipIt = 0 + solveMem(arr, n, 1, idx+1, dp);
    profit = max(buyIt, skipIt);
}
else{
    int sellIt = arr[idx] + solveMem(arr, n, 1, idx+1, dp);
    int skipIt = 0 + solveMem(arr, n, 0, idx+1, dp);
    
    profit = max(sellIt, skipIt);
}

return dp[buy][idx] = profit;
}

int solveTab(int arr[], int n) {
    vector<vector<int>> dp(2, vector<int>(n, 0));
    
    // Initialize the base cases
    dp[1][0] = -arr[0];
    
    for (int i = 1; i < n; i++) {
        // Transition for buying or skipping
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - arr[i]);
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + arr[i]);
    }
    
    return max(dp[0][n - 1], dp[1][n - 1]);
}

int main(){

int arr[] = {7, 6, 5, 4, 3, 10};
int n = sizeof(arr)/sizeof(int);

vector<vector<int>> dp(2, vector<int>(n, -1));

int buy = 1;
int idx = 0;
cout<<solveMem(arr, n, buy, idx, dp)<<endl;
cout<<solveTab(arr, n)<<endl;

    return 0;
}