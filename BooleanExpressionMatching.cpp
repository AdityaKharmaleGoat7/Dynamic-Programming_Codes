#include <bits/stdc++.h>
using namespace std;

int solve(string str, int i, int j, bool isTrue){
    if(i > j){
        return true;
    }

    if(i == j){
        if(isTrue == true){
            return str[i] == 'T';
        }
        else{
            return str[i] == 'F';
        }
    }

int ans = 0;
    for(int k = i+1;k <= j-1;k+=2){
        int lt = solve(str, i, k-1, true);
        int lf = solve(str, i, k-1, false);
        int rt = solve(str, k+1, j, true);
        int rf = solve(str, k+1, j, false);

        if(str[k] == '&'){
            if(isTrue == true){
                ans += lt*rt;
            }
            else{
                ans += lt*rf + rf*lf + lf*rf;
            }
        }

        else if(str[k] == '|'){
            if(isTrue == true){
                ans += lt*rf + lf*rt + lt*rt;
            }
            else{
                ans += lf*rf;
            }
        }
        else if(str[k] == '^'){
            if(isTrue == true){
                ans += lf*rt + lt*rf;
            }
            else{
                ans += lt*rt + lf*rf;
            }
        }
    }
return ans;
}

int solveMem(string str, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp){
    if(i > j){
        return true;
    }

    if(i == j){
        if(isTrue == true){
            return str[i] == 'T';
        }
        else{
            return str[i] == 'F';
        }
    }
if(dp[i][j][true] != -1){
    return dp[i][j][true];
}

int ans = 0;
    for(int k = i+1;k <= j-1;k+=2){
        int lt = solveMem(str, i, k-1, true, dp);
        int lf = solveMem(str, i, k-1, false, dp);
        int rt = solveMem(str, k+1, j, true, dp);
        int rf = solveMem(str, k+1, j, false, dp);

        if(str[k] == '&'){
            if(isTrue == true){
                ans += lt*rt;
            }
            else{
                ans += lt*rf + rf*lf + lf*rf;
            }
        }

        else if(str[k] == '|'){
            if(isTrue == true){
                ans += lt*rf + lf*rt + lt*rt;
            }
            else{
                ans += lf*rf;
            }
        }
        else if(str[k] == '^'){
            if(isTrue == true){
                ans += lf*rt + lt*rf;
            }
            else{
                ans += lt*rt + lf*rf;
            }
        }
    }
return dp[i][j][true] = ans;
}

int main(){

string str = "T|T^F";

cout<<solve(str, 0, str.length()-1, true)<<endl;

int n = str.length();
vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int>(2, -1)));
// cout<<solveMem(str, 0, str.length()-1, true, dp)<<endl;

    return 0;
}