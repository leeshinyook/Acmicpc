#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int arr[301][301];
int cnt[301][301];
bool visited[301][301];
int L;
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
struct TARGET{
    int x, y;
};
TARGET night, target;
queue<pair<int, int>> q;
void BFS(int a, int b) {
    q.push({a, b});
    visited[a][b] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        if(target.x == x && target.y == y) {
            cout << cnt[x][y] << '\n';
            return;
        }
        q.pop();
        for(int i = 0 ; i < 8; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx < 0 || mx >= L || my < 0 || my >= L) continue;
            if(visited[mx][my]) continue;
            visited[mx][my] = true;
            q.push({mx, my});
            cnt[mx][my] = cnt[x][y] + 1;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TC;

    cin >> TC;
    while(TC--) {
        memset(visited, false, sizeof(visited));
        memset(cnt, 0, sizeof(cnt));
        while(!q.empty()) q.pop();
        cin >> L;
        cin >> night.x >> night.y;
        cin >> target.x >> target.y;
        BFS(night.x, night.y);
    }


}