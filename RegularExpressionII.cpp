// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
#include <bits/stdc++.h>
using namespace std;
bool _isMatch(string &str, int s, string &pat, int p){
    if(p == pat.length())        
    return s == str.size();

    bool star = p < pat.size()-1 and pat[p + 1] == '*';
    bool match = s < str.size() and  (pat[p] == '.' or str[s] == pat[p]);
    // if theres kleene
    if(star){
        // dont match rec, match rec.
        return _isMatch(str, s, pat, p+2) 
            or ( match and _isMatch(str, s+1, pat, p));
    }
    return match and _isMatch(str, s+1, pat, p+1);
}


int isMatch(string str, string pat) {
    return _isMatch(str, 0, pat, 0);
}

int main(){
string A = "mississipi";
string B = "mis*is.*pi";
cout<<isMatch(A, B);

    return 0;
}