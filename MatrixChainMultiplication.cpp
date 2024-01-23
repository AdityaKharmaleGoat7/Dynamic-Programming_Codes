#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j){
    if(i >= j){
        return 0;
    }

    int mini = INT_MAX;

    for(int k = i;k <= j-1;k++){
        int tempAns = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j]; 

        mini = min(mini, tempAns);
    }
    return mini;
}

int solveMem(int arr[], int i, int j, vector<vector<int>> &dp){
    if(i >= j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = INT_MAX;

    for(int k = i;k <= j-1;k++){
        int tempAns = solveMem(arr, i, k, dp) + solveMem(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j]; 

        mini = min(mini, tempAns);
    }
    return dp[i][j] = mini;
}

int main(){
int arr[] = {40, 20, 30, 10, 30};
int n = sizeof(arr)/sizeof(int);

int i = 1;
int j = n-1;

cout<<solve(arr, i, j)<<endl;

vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
cout<<solveMem(arr, i, j, dp)<<endl;


    return 0;
}