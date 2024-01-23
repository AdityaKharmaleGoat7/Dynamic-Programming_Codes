#include <bits/stdc++.h>
using namespace std;

int main(){

int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
int rod = 8;

int n = sizeof(length)/sizeof(int);

vector<vector<int>> dp(n+1, vector<int>(rod+1));

for(int i = 0;i <= n;i++){
    for(int j = 0;j <= rod;j++){
        if(i == 0 || j == 0){
            dp[i][j] = 0;
        }
    }
}

for(int i = 1;i <= n;i++){
    for(int j = 1;j <= rod;j++){
        if(j >= length[i-1]){
            dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
        }
        else{
            dp[i][j] = dp[i-1][j];
        }
    }
}
cout<<dp[n][rod]<<endl;

    return 0;
}