#include <bits/stdc++.h>
using namespace std;

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

int i = n, j = m;

string ans = "";

while(i > 0 && j > 0){
    if(x[i-1] == y[j-1]){
        ans += x[i-1];
        i--;
        j--;
    }
    else{
        if(dp[i-1][j] < dp[i][j-1]){
            j--;
        }
        else{
            i--;
        }
    }
}

reverse(ans.begin(), ans.end());
cout<<ans<<endl;
    return 0;
}