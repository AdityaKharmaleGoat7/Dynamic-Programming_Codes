#include <bits/stdc++.h>
using namespace std;

//Minimum number of slashes to make a string palindrome

bool isPalindrome(int i, int j, string str){
    
    while(i < j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string str, int i, int j){
    if(i >= j){
        return 0;
    }

    if(isPalindrome(i, j, str)){
        return 0;
    }

    int mini = INT_MAX;

    for(int k = i;k <= j-1;k++){
        int tempAns = solve(str, i, k) + solve(str, k+1, j) + 1;
        mini = min(mini, tempAns);
    }

    return mini;
}

int solveMem(string str, int i, int j, vector<vector<int>> &dp){
    if(i >= j){
        return 0;
    }

    if(isPalindrome(i, j, str)){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = INT_MAX;

    for(int k = i;k <= j-1;k++){
        int tempAns = solveMem(str, i, k, dp) + solveMem(str, k+1, j, dp) + 1;
        mini = min(mini, tempAns);
    }

    return dp[i][j] = mini;
}


int main(){

string str = "aab";
int n = str.size();
// cout<<solve(str, 0, str.length()-1)<<endl;
vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
cout<<solve(str, 0, str.length()-1)<<endl;
// cout<<solveMem(str, 0, str.length()-1, dp)   <<endl;
    return 0;
}