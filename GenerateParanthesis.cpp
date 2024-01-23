#include <bits/stdc++.h>
using namespace std;

void solve(int open, int close, string ans){
    if(open == 0 && close == 0){
        cout << ans << " ";
        return;
    }
    if(open > 0){
        solve(open-1, close, ans + '(');
    }
    if(close > 0 && open < close){
        solve(open, close-1, ans + ')');
    }
}

int main(){
    int n;
    cin >> n;

    int open = n;
    int close = n;

    string ans = "";
    solve(open, close, ans);

    return 0;
}
