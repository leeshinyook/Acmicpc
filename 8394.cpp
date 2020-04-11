#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int dp[10000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 10000000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
    }
    int N;
    cin >> N;
    cout << dp[N];
}