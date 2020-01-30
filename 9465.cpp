#include <iostream>
#include <vector>
#include <algorithm>

#define FASTSTD ios::sync_with_stdio(0)
#define FASTCIN cin.tie(0)
using namespace std;

int arr[2][100001];
int dp[2][100001];
int main() {
    FASTSTD;
    FASTCIN;
    int TESTCASE;
    cin >> TESTCASE;

    while(TESTCASE--) {
        int T;
        cin >> T;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < T; j++) {
                cin >> arr[i][j];
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = arr[0][1] + dp[1][0];
        dp[1][1] = arr[1][1] + dp[0][0];

        for(int i = 2; i < T; i++) {
            dp[0][i] = arr[0][i] + max(dp[1][i - 2], dp[1][i - 1]);
            dp[1][i] = arr[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
        }
        cout << max(dp[0][T - 1], dp[1][T - 1]) << "\n";

    }
    return 0;
}