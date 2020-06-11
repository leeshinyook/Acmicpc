#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int dp[1025][1025], arr[1025][1025];
int N, M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            dp[i][j] = dp[i][j - 1] + arr[i][j];
        }
    }
    for(int i = 0; i < M; i++) {
        int w, x1, y1, x2, y2, value;
        cin >> w;
        if (!w) {
            cin >> y1 >> x1 >> value;
            int updateValue = value - (dp[y1][x1] - dp[y1][x1 - 1]);
            for(int i = x1; i <= N; i++) {
                dp[y1][i] += updateValue;
            }
        } else {
            cin >> y1 >> x1 >> y2 >> x2;
            int ret = 0;
            for(int i = y1; i <= y2; i++) {
                ret += (dp[i][x2] - dp[i][x1 - 1]);
            }
            cout << ret << '\n';
        }
    }
}



