#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;


long long dp[65][10];
long long ans[65];
int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    for(int i = 2; i < 65; i++) {
        long long sum = 0;
        for(int j = 0; j < 10; j++) {
            dp[i][j] = dp[i - 1][j] + sum;
            sum += dp[i - 1][j];
        }
        ans[i] = 0;
        for(int j = 0; j < 10; j++) {
            ans[i] += dp[i][j];
        }
    }
    ans[1] = 10;

    while(N--) {
        int num;
        cin >> num;
        cout << ans[num] << "\n";
    }
}