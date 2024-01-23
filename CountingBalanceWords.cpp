#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int countBalancedWords(int n, int d) {
    vector<vector<long long>> dp(n + 1, vector<long long>(26, 0));

    // Base case: a single character word has one way for each character
    for (int charIdx = 0; charIdx < 26; charIdx++) {
        dp[1][charIdx] = 1;
    }

    // Fill the dp array
    for (int length = 2; length <= n; length++) {
        for (int charIdx = 0; charIdx < 26; charIdx++) {
            for (int prevCharIdx = 0; prevCharIdx < 26; prevCharIdx++) {
                if (abs(charIdx - prevCharIdx) <= d) {
                    dp[length][charIdx] = (dp[length][charIdx] + dp[length - 1][prevCharIdx]) % MOD;
                }
            }
        }
    }

    long long total = 0;
    for (int charIdx = 0; charIdx < 26; charIdx++) {
        total = (total + dp[n][charIdx]) % MOD;
    }

    return total;
}

int main() {
    int n, d;
    cin >> n >> d;
    int result = countBalancedWords(n, d);
    cout << result << endl;
    return 0;
}
