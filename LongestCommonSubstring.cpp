#include <bits/stdc++.h>
using namespace std;


int main(){
string x = "abcdgh";
string y = "abedfhr";
int n = x.length();
int m = y.length();

vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
int ans = 0;
for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
        if(x[i-1] == y[j-1]){
            dp[i][j] = 1 + dp[i-1][j-1];
            ans = max(ans, dp[i][j]);
        }
        else{
            dp[i][j] = 0;
        }
    }
}

cout<<ans<<endl;

    return 0;
}