#include <bits/stdc++.h>
using namespace std;

int solveMem(string A,string B, int i, int j, vector<vector<int>> &dp){
    if(j < 0){
        return 1;
    }
    if(i < 0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(A[i] == B[j]){
        return dp[i][j] = (solveMem(A, B, i-1, j-1, dp) + solveMem(A, B, i-1, j, dp)) ;
    }

    else{
        return dp[i][j] = solveMem(A, B, i-1, j, dp);
    }
}
int solveTab(string A, string B) {
    int m = A.length();
    int n = B.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1; 
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[m][n]; 
}

int main(){
string A = "babgbag";
string B = "bag";
vector<vector<int>> dp(A.size()+1, vector<int>(B.size() + 1, -1));

int i = A.size(), j = B.size();
cout<<solveTab(A, B)<<endl;



    return 0;
}