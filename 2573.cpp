#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int arr[301][301];
int meltArr[301][301];
bool visited[301][301];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int M, N;
queue<pair<int, int>> q;
void BFS(int x, int y) {
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()) {
        int mx = q.front().first;
        int my = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int lx = dx[i] + mx;
            int ly = dy[i] + my;
            if(lx < 1 || lx > N || ly < 1 || ly > M) continue;
            if(visited[lx][ly]) continue;
            if(arr[lx][ly]) {
                visited[lx][ly] = true;
                q.push({lx, ly});
            }
        }
    }
}
int Melt(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!arr[nx][ny]) cnt++;
    }
    return cnt;
}
int main() {
    int cnt = 0;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    int year = 0;
    while(true) {
        int landCnt = 0;
        memset(visited, false, sizeof(visited));
        memset(meltArr, 0, sizeof(meltArr));
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(arr[i][j] && !visited[i][j]) {
                    landCnt++;
                    BFS(i, j);
                }
            }
        }
        if(landCnt >= 2) {
            cout << year;
            return 0;
        };
        if(landCnt == 0) {
            cout << 0;
            return 0;
        }

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(arr[i][j]) {
                    meltArr[i][j] = arr[i][j] - Melt(i, j);
                    if(meltArr[i][j] < 0) meltArr[i][j] = 0;
                }
            }
        }

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                arr[i][j] = meltArr[i][j];
            }
        }
        year++;
    }


}