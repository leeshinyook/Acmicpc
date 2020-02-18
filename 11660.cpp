#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;

int dp[1026][1026];
int arr[1026][1026];
int N, M;
struct Point {
    int x;
    int y;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Point p1, p2;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    for(int i = 0; i < M; i++) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        cout << dp[p2.x][p2.y] + dp[p1.x - 1][p1.y - 1] - dp[p1.x - 1][p2.y] - dp[p2.x][p1.y - 1];
        cout << '\n';
    }



}