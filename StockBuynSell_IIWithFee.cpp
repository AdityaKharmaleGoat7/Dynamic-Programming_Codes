#include <bits/stdc++.h>
using namespace std;

int solveMem(int arr[], int n, int buy, int idx, vector<vector<int>> &dp, int fee){

if(idx == n){
    return 0;
}
if(dp[buy][idx] != -1){
    return dp[buy][idx];
}
int profit = 0;

if(buy == 1){
    int buyIt = -arr[idx] + solveMem(arr,n, 0, idx+1, dp, fee);
    int skipIt = 0 + solveMem(arr, n, 1, idx+1, dp, fee);
    profit = max(buyIt, skipIt);
}
else{
    int sellIt = arr[idx] + solveMem(arr, n, 1, idx+1, dp, fee) - fee;
    int skipIt = 0 + solveMem(arr, n, 0, idx+1, dp, fee);
    
    profit = max(sellIt, skipIt);
}

return dp[buy][idx] = profit;
}


int main(){

int arr[] = {7, 6, 5, 4, 3, 10};
int n = sizeof(arr)/sizeof(int);

vector<vector<int>> dp(2, vector<int>(n, -1));

int fee = 2;

int buy = 1;
int idx = 0;
cout<<solveMem(arr, n, buy, idx, dp, fee)<<endl;

    return 0;
}