#include <iostream>
#include <vector>
#include <algorithm>

#define FASTSTD ios::sync_with_stdio(0)
#define FASTCIN cin.tie(0)
using namespace std;

int main() {
    FASTSTD;
    FASTCIN;
    int dp[51];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i < 51; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1000000007;
    }
    int n;
    cin >> n;
    cout << dp[n];
    return 0;
}