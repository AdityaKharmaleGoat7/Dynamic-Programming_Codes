#include <bits/stdc++.h>
using namespace std;

int solve(int coins[], int sum, int n){

vector<vector<int>> dp(n+1, vector<int>(sum+1));

dp[0][0] = 1;

for(int i = 0;i <= n;i++){
    for(int j = 0;j <= sum;j++){
        if(i == 0 && i != j){
            dp[i][j] = 0;
        }
        if(j == 0 && i != j){
            dp[i][j] = 1;
        }
    }
}

for(int i = 1;i <= n;i++){
    for(int j = 1;j <= sum;j++){
        if(coins[i-1] <= j){
            dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
        }
        else{
            dp[i][j] = dp[i-1][j];
        }
  }
}

return dp[n][sum];
}

int main(){

int coins[] = {1, 2, 3};
int sum = 5;
int n = sizeof(coins)/sizeof(int);

cout<<solve(coins, sum, n)<<endl;


    return 0;
}