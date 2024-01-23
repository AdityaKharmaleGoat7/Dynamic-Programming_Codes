#include <bits/stdc++.h>
using namespace std;

bool solve(string &str, string &pattern, int i, int j,vector<vector<int>> &dp){
    
if(i < 0 && j < 0){
    return true;
}

    if(i >= 0 && j  < 0){
        return false;
    }

if(i <  0 && j >= 0){
    for(int k = 0;k <= j;k++){
        if(pattern[k] != '*'){
            return false;
        }
    }
        return true;
}

if(dp[i][j] != -1){
    return dp[i][j];
}

if(str[i] == pattern[j] || pattern[j] == '?'){
    return dp[i][j] = solve(str, pattern, i-1, j-1, dp);
}
else if(pattern[j] == '*'){
return dp[i][j] =(solve(str, pattern, i-1, j, dp) || solve(str, pattern, i-1, j-1, dp));
}
else{
    return false;
}
}

int main(){
string str; cin>>str;
string pattern; 
cin>>pattern;

vector<vector<int>> dp(str.length(), vector<int>(pattern.length(), -1));

cout<<solve(str, pattern, str.length()-1, pattern.length()-1, dp)<<endl;

    return 0;
}