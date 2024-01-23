#include <bits/stdc++.h>
using namespace std;
unordered_set<string> wordSet;

    bool solve(string s, vector<int>& memo) {
        if (s.length() == 0) {
            return true;
        }

        if (memo[s.length()] != -1) {
            return memo[s.length()] == 1;
        }

        int length = s.length();

        for (int i = 1; i <= length; i++) {
            string prefix = s.substr(0, i);

            if (wordSet.find(prefix) != wordSet.end() && solve(s.substr(i), memo)) {
                memo[length] = 1;
                return true;
            }
        }

        
        return memo[length] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length() + 1, -1);
        return solve(s, memo);
    }
int main(){
string s = "applepenapple";
vector<string> wordDict = {"apple", "pen"};
cout<<wordBreak(s, wordDict);

    return 0;
}
