#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int diff, int arr[], unordered_map<int, int> dp[]){
    if(idx < 0){
        return 0;
    }

    if(dp[idx].count(diff)){
        return dp[idx][diff];
    }

    int ans = 0;

    for(int j = idx-1; j>=0; j--){
        if(arr[idx] - arr[j] == diff)
        ans = max(ans, 1 + solve(j, diff, arr, dp));
    }

    return dp[idx][diff] = ans;
}

int LengthOfLongestAP(int arr[], int n){

    if(n <= 2){
        return n;
    }

    int ans = 0;

    unordered_map<int, int> dp[n+1];

    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            ans = max(ans, 2 + solve(i, arr[j]-arr[i], arr, dp));
        }
    }

    return ans;
}

int main(){
int arr[] = {1, 7, 10, 13, 14, 19};
int n = sizeof(arr)/sizeof(int);

// cout<<LengthOfLongestAP(arr, n);


//Tabulation Method
int ans = 0;
unordered_map<int, int> dp[n+1];

for(int i = 1;i < n;i++){
    for(int j = 0;j < i;j++){
        int diff = arr[i] - arr[j];
        int cnt = 1;

        if(dp[j].count(diff)){
            cnt = dp[j][diff];
        }

        dp[i][diff] = 1 + cnt;
        ans = max(ans, dp[i][diff]);
    }
}

cout<<ans<<endl;
    return 0;
}