#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, Q;
int arr[1001][1001];
int dp[1001][1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    for(int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        int size = 0;
        int area = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        size = (x2 - x1 + 1) * (y2 - y1 + 1);
        area = dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1];
        cout << area / size << '\n';
    }

};
