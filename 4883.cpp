#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N;
int arr[100001][4];
int dp[100001][4];
void Init() {
    for(int i = 0; i < 100001; i++) {
        for(int j = 0; j < 4; j++) {
            arr[i][j] = 0;
            dp[i][j] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int k = 1;; k++) {
        cin >> N;
        if(N == 0) break;
        Init();
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= 3; j++) {
                cin >> arr[i][j];
            }
        }
        dp[1][2] = arr[1][2];
        dp[1][3] = dp[1][2] + arr[1][3];
        dp[2][1] = dp[1][2] + arr[2][1];
        dp[2][2] = min(dp[2][1] , min(dp[1][3], dp[1][2])) + arr[2][2];
        dp[2][3] = min(dp[1][2] , min(dp[2][2], dp[1][3])) + arr[2][3];
        for(int i = 3; i <= N; i++) {
            for(int j = 1; j <= 3; j++) {
                if(j == 1) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + arr[i][j];
                }
                if(j == 2) {
                    int n1 = min(dp[i][j - 1], dp[i - 1][j - 1]);
                    int n2 = min(dp[i - 1][j] , dp[i - 1][j + 1]);
                    dp[i][j] = min(n1, n2) + arr[i][j];
                }
                if(j == 3) {
                    dp[i][j] = min(dp[i - 1][j],min(dp[i][j - 1], dp[i - 1][j - 1])) + arr[i][j];
                }
            }
        }
        cout << k <<". " << dp[N][2] << '\n';
    }
    return 0;
}
