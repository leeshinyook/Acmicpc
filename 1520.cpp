#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

int arr[501][501];
int dp[501][501];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int M, N;
int DFS(int x, int y) {
    if(x == 1 && y == 1) return 1;
    if(dp[x][y] == -1) {
        dp[x][y] = 0;
        for(int i = 0; i < 4; i++) {
            int mx = dx[i] + x;
            int my = dy[i] + y;
            if (mx < 1 || mx > M || my < 1 || my > N) continue;
            if (arr[x][y] < arr[mx][my]) {
                dp[x][y] += DFS(mx, my);
            }
        }
    }
    return dp[x][y];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout << DFS(M, N);

}