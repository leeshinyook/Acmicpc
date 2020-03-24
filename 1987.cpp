#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[21][21];
char arr[21][21];
deque<char> tracked;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int N, M;
bool IsCheck(int x, int y) {
    for(auto u : tracked) {
        if(arr[x][y] == u) return true; // 경로를 거친 것이 있다면,
    }
    return false; // 경로에 거친 것이 없다면
}
int ans = INT_MIN;
void DFS(int x, int y, int cnt) {
    if(ans < cnt) ans = cnt;
    for(int i = 0; i < 4; i++) {
        int mx = dx[i] + x;
        int my = dy[i] + y;
        if(mx < 1 || mx > N || my < 1 || my > M) continue;
        if(IsCheck(mx, my)) continue;
        tracked.push_front(arr[mx][my]);
        DFS(mx, my, cnt +  1);
        tracked.pop_front();
    }
}
int main () {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    tracked.push_front(arr[1][1]);
    visited[1][1] = true;
    DFS(1, 1, 1);
    cout << ans;

}
