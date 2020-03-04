#include <iostream>

using namespace std;

long long dp[202][202];
int N, K;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for(int i = 0; i <= 201; i++) {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= 201; i++) {
        for(int j = 0; j <= 201; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000000;
            }
        }
    }
    cout << dp[N + 1][K - 1] % 1000000000;
}