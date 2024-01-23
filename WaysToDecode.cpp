#include <bits/stdc++.h>
using namespace std;

int solve(string A, int pos, int n, vector<int> &dp){
    if(pos == n){
        return 1;
    }
    if(A[pos] == '0'){
        return 0;
    }

    if(dp[pos] != -1){
        return dp[pos];
    }
    
    int count = solve(A, pos+1, n, dp);
     
    if(pos < n-1 && A.substr(pos, 2) < "27"){
        count = count + solve(A, pos+2, n, dp);
    }
    return dp[pos] = count;
}

int numDecodings(string A) {
int n = A.size();
vector<int> dp(n+1, -1);
return solve(A, 0, n, dp);
}

int main(){

string str = "123";
cout<<numDecodings(str)<<endl;
    return 0;
}