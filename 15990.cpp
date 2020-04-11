#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

long long dp[100001][4];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 0;

    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;

    dp[2][1] = 0;
    dp[2][2] = 1;
    dp[2][3] = 0;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for(int i = 4; i <= 100000; i++) {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
    }
    int N;
    cin >> N;
    while(N--) {
        int num;
        cin >> num;
        cout << (dp[num][1] + dp[num][2] + dp[num][3]) % 1000000009 << '\n';
    }
}