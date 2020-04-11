#include <iostream>
#include <vector>
#include <set>
using namespace std;

int arr[301][301];
int dp[301][301];
int N, M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            int temp = max(arr[i][j] + dp[i - 1][j], arr[i][j] + dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], temp);
        }
    }
    cout << dp[N][M];
}