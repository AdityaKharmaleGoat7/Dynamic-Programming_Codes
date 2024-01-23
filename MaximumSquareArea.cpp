#include <bits/stdc++.h>
using namespace std;
   
int solve(int arr[][4], int i, int j, int &maxi, int n){
    if(i >= n || j >= n){
        return 0;
    } 

    int right = solve(arr, i, j+1, maxi, n);
    int diagonal = solve(arr, i+1, j+1, maxi, n);
    int down = solve(arr, i+1, j, maxi, n);

    if(arr[i][j] == 1){
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else{
        return 0;
    }
}


int solveMem(int arr[][4], int i, int j, int &maxi, int n, vector<vector<int>> &dp){
    if(i >= n || j >= n){
        return 0;
    } 

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = solveMem(arr, i, j+1, maxi, n, dp);
    int diagonal = solveMem(arr, i+1, j+1, maxi, n, dp);
    int down = solveMem(arr, i+1, j, maxi, n, dp);

    if(arr[i][j] == 1){
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return dp[i][j] = ans;
    }
    else{
        return 0;
    }
}

int solveTab(int arr[][4], int &maxi, int n){
vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

for(int i = n-1;i >= 0;i--){
    for(int j = n-1;j >= 0;j--){
    int right = dp[i][j+1];
    int diagonal = dp[i+1][j+1];
    int down = dp[i+1][j];

    if(arr[i][j] == 1){
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
    }    

    else{
        dp[i][j] = 0;
    }
}
}

return dp[0][0];
}


int main(){

int arr[4][4] = {{1, 1, 1, 1},
                 {1, 1, 1, 1},
                 {1, 1, 1, 0}};

int i = 0, j = 0, maxi = 0;
int n = 4;

vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

// solve(arr, i, j, maxi, n);
// solveMem(arr, i, j, maxi, n,dp);
solveTab(arr, maxi, n);

cout<<maxi<<endl;
    return 0;
}