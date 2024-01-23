#include <bits/stdc++.h>
using  namespace std;

int main(){

int arr[] ={0,1,0,2,1,0,1,3,2,1,2,1};
int n = sizeof(arr)/sizeof(int);

int ans = 0;

int maxL[n];
int maxR[n];

maxL[0] = arr[0];
maxR[n-1] = arr[n-1];


for(int i = 1;i < n;i++){
    maxL[i] = max(maxL[i-1], arr[i]);
}

for(int i = n-2;i >= 0;i--){
    maxR[i] = max(maxR[i+1], arr[i]);
}

for(int i = 1;i <=n-2;i++){
    if(min(maxL[i], maxR[i])-arr[i] >= 0){
        ans += 1*(min(maxL[i], maxR[i])-arr[i]);
    }
}

cout<<ans;

    return 0;
}