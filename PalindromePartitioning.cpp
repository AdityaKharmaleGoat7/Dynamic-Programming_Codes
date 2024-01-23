#include <bits/stdc++.h>
using namespace std;

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

int PalindromePartitionII(int i, string str, int n){
    if(i == n){
        return 0;
    }

    int mincost = INT_MAX;

    for(int j = i;j < n;j++){
        if(isPalindrome(i, j, str)){
           int cost = 1 + PalindromePartitionII(j+1, str, n);
            mincost = min(mincost, cost);
        }

    }

    return mincost;
}

int main(){

string str = "bababacdebed";
int n = str.size();

cout<<PalindromePartitionII(0, str, n)-1<<endl;



    return 0;
}