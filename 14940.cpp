#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int arr[1001][1001];
bool visited[1001][1001];
int dist[1001][1001] = {-1, };
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int N, M;
vector<int> ans;

queue<pair<int, int>> q;

void BFS(int x, int y) {
    q.push({x, y});
    visited[x][y] = true;
    dist[x][y] = 0;
    while(!q.empty()) {
        int mx = q.front().first;
        int my = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int lx = dx[i] + mx;
            int ly = dy[i] + my;
            if(lx < 1 || lx > N || ly < 1 || ly > M) continue;
            if(visited[lx][ly] || !arr[lx][ly]) continue;
            visited[lx][ly] = true;
            dist[lx][ly] = dist[mx][my] + 1;
            q.push({lx, ly});
        }
    }
}
void notToTouch() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j] && !dist[i][j]) {
                dist[i][j] = -1;
            }
        }
    }
}
int main() {
    cin >> N >> M;
    int Tx, Ty;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) {
               Tx = i, Ty = j;
            }
        }
    }
    BFS(Tx, Ty);
    notToTouch();
    dist[Tx][Ty] = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}

