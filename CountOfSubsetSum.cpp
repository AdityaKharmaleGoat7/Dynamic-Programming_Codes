#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int k, int idx)
{
    if(idx < 0 && k > 0){
        return 0;
    }
    if(k == 0){
        return 1;
    }

    if(k - arr[idx] >= 0){
    int include = solve(arr, k-arr[idx], idx-1);
    int exclude = solve(arr, k, idx-1);
    return include + exclude;
    }

    else{
        return solve(arr, k, idx-1);
    }

}

int main(){
int arr[] = {2, 3, 5, 6, 8, 10, 9, 1};
int sum = 10;
int n = sizeof(arr)/sizeof(int);
// cout<<solve(arr, sum, n-1);
vector<vector<int>> dp(n+1, vector<int>(sum+1));

dp[0][0] = 1;

for(int i = 0;i <= n;i++){
    for(int j = 0;j <= sum;j++){
        if(i == 0 && i != j){
            dp[i][j] = 0;
        }
        if(j == 0 && j != i){
            dp[i][j] = 1;
        }
    }
}

for(int i = 1;i <= n;i++){
    for(int j = 1;j <= sum;j++){
        if(arr[i-1] <= j){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
        }
        else
        dp[i][j] = dp[i-1][j];
    }
}

cout<<dp[n][sum];

    return 0;
}