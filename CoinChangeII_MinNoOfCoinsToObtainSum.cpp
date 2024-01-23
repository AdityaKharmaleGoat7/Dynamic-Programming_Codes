#include <bits/stdc++.h>
using namespace std;

int main(){

int coins[] = {2, 3, 7};
int sum = 11;
int n = sizeof(coins)/sizeof(int);

vector<vector<int>> dp(n+1, vector<int>(sum+1));

for(int i = 0;i <= n;i++){
    for(int j = 0;j <= sum;j++){
        if(i == 0){
            dp[i][j] = INT_MAX-1;
        }
        if(j == 0 && i!=j){
            dp[i][j] = 0;
        }
    }
}

for(int i = 0;i <= n;i++){
    for(int j = 0;j <= sum;j++){
cout<<dp[i][j]<<" ";
    }cout<<endl;
}

for(int j = 1;j <= sum;j++){
    if(j%coins[0] == 0){
        dp[1][j] = j/coins[0];
    }
    else{
        dp[1][j] = INT_MAX-1;
    }
}

for(int i = 0;i <= n;i++){
    for(int j = 0;j <= sum;j++){
cout<<dp[i][j]<<" ";
    }cout<<endl;
}


for(int i = 2;i <= n;i++){
    for(int j = 1;j <= sum;j++){
        if(coins[i-1] <= j){
            dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
        }
        else{
            dp[i][j] = dp[i-1][j];
        }
    }
}

cout<<dp[n][sum]<<endl;

    return 0;
}