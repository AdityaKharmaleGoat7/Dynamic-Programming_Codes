#include <bits/stdc++.h>
using namespace std;

int solve(string x, string y, int i, int j){
    if(i < 0 ||j < 0){
        return 0;
    }

    if(x[i] == y[j]){
        return 1 + solve(x, y, i-1, j-1);
    }
    else{
        return max(solve(x, y, i-1, j), solve(x, y, i, j-1));
    }
}

int main(){
string x = "abcdgh";
string y = "abedfhr";
int n = x.length();
int m = y.length();
vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
        if(x[i-1] == y[j-1]){
            dp[i][j] = 1 + dp[i-1][j-1];
        }
        else{
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}
cout<<dp[n][m]<<endl;
// cout<<solve(x, y, x.length()-1, y.length()-1)<<endl;

    return 0;
}