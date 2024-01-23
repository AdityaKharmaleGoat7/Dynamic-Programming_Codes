#include <bits/stdc++.h>
using namespace std;

int solveMem(int arr[], int n, int buy, int idx, int limit, vector<vector<vector<int>>> &dp){

if(idx == n){
    return 0;
}

if(limit == 0){
    return 0;
}

if(dp[buy][idx][limit] != -1){
    return dp[buy][idx][limit];
}
 
int profit = 0;

if(buy == 1){
    int buyIt = -arr[idx] + solveMem(arr,n, 0, idx+1, limit, dp);
    int skipIt = 0 + solveMem(arr, n, 1, idx+1, limit, dp);
    profit = max(buyIt, skipIt);
}
else{
    int sellIt = arr[idx] + solveMem(arr, n, 1, idx+1, limit-1, dp);
    int skipIt = 0 + solveMem(arr, n, 0, idx+1, limit, dp);
    
    profit = max(sellIt, skipIt);
}

return dp[buy][idx][limit] = profit;
}

int main(){

int arr[] = {7, 6, 5, 4, 3, 10};
int n = sizeof(arr)/sizeof(int);
 
vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(3, -1)));

int buy = 1;
int idx = 0;
cout<<solveMem(arr, n, buy, idx, 2, dp)<<endl;
 

    return 0;
}