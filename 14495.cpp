#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

long long dp[120];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= 116; i++) {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
    int N;
    cin >> N;
    cout << dp[N];
}