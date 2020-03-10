#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int cnt = 0;
int arr[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;
void search() {
    while(!q.empty()) {
        int mx = q.front().first;
        int my = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = mx + dx[i];
            int ny = my + dy[i];
            if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if(arr[nx][ny] == -1) {
                dist[nx][ny] = -1;
                continue;
            }
            if(arr[nx][ny] == 0) {
                visited[nx][ny] = true;
                arr[nx][ny] = 1;
                dist[nx][ny] = dist[mx][my] + 1;
                q.push({nx, ny});
            }
        }
    }
}
int findMax() {
    int max = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(dist[i][j] > max) max = dist[i][j];
        }
    }
    return max;
}
bool findEdge() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 0 && dist[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    search();
    if(findEdge()) {
        cout << -1;
        return 0;
    } else {
        cout << findMax();
    }


}
