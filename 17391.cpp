#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int arr[301][301];
bool visited[301][301];
int N, M;
int mx[4] = {0, 1};
int my[4] = {1, 0};
queue<pair<pair<int, int>, int>> q;
void BFS(int a, int b) {
    q.push({{a, b}, 0 });
    visited[a][b] = true;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        int dist = arr[x][y];
        if(x == N && y == M) {
            cout << d;
            return;
        }
        q.pop();
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= dist; j++) {
                int dx = x + mx[i] * j;
                int dy = y + my[i] * j;
                if(dx < 1 || dx > N || dy < 1 || dy > M) continue;
                if(visited[dx][dy]) continue;
                visited[dx][dy] = true;
                q.push({{dx, dy}, d + 1});
            }
        }

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    BFS(1, 1);
}