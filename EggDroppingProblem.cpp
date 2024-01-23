#include <bits/stdc++.h>
using namespace std;

int solve(int e, int f){
    if(f == 0 || f == 1){
        return f;
    }

    if(e == 1){
        return f;
    }

    int mini = INT_MAX;

    for(int k = 1;k <= f;k++){
        int temp = 1 + max(solve(e-1, k-1), solve(e, f-k));

        mini = min(mini, temp);
    }

    return mini;
}

int main(){

int e, f;
e = 3;
f = 5;

cout<<solve(e, f)<<endl;

    return 0;
}