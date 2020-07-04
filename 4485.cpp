
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 987654321
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[126][126];
int dp[126][126];
int N;
void Init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] = MAX;
        }
    }
}
void Search() {
    queue<pair<int, int>> q;
    q.push({1, 1});
    dp[1][1] = arr[1][1];
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if(dp[nx][ny] > dp[x][y] + arr[nx][ny]) {
                dp[nx][ny] = dp[x][y] + arr[nx][ny];
                q.push({nx, ny});
            }
        }
    }
}
int main() {
    IOS;
    for(int i = 1;;i++) {
        cin >> N;
        if(!N) return 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                cin >> arr[i][j];
            }
        }
        Init();
        Search();
        cout << "Problem "<< i << ": " << dp[N][N] << endl;
    }
}