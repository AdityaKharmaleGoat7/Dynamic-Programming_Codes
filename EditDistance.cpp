#include <bits/stdc++.h>
using namespace std;

int solve(string A, string B, int i, int j){
    if(i < 0 && j < 0){
        return 0;
    }

    if(i < 0){
        return j + 1;
    }
    if(j < 0){
        return i + 1;
    }

    if(A[i] == B[j]){
        return solve(A, B, i-1, j-1);
    }
    else{
        return min(1 + solve(A, B, i, j-1), min(1 + solve(A, B, i-1, j), 1 + solve(A, B, i-1, j-1)));
    }
}


int main(){

string A = "Anshuman";
string B = "Antihuman";

int i = A.size()-1, j = B.size()-1;
cout<<solve(A, B, i, j);


    return 0;
}