#include <bits/stdc++.h>

using namespace std;

int solve(int val, int arr[], int n){
    if(n < 0 && val > 0){
        return 0;
    }
    if(val == 0){
        return 1;
    }

    if(val - arr[n] >= 0){
        return solve(val - arr[n], arr, n-1) + solve(val, arr, n-1);
    }
    else{
        return solve(val, arr, n-1);
    }
}

int main(){
int arr[] = {1, 1, 2, 3};
int diff = 1;

int n = sizeof(arr)/sizeof(int);
int sum = 0;

for(int i = 0;i < n;i++){
    sum += arr[i];
}

int val = (diff + sum)/2;

if((diff+sum)%2 == 0){
cout<<solve(val, arr, n-1);
}
else{
    cout<<0<<endl;
}



    return 0;
}