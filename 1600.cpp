#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int hdx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hdy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int arr[201][201];
bool visited[201][201][201];
int N, M, K;
queue<pair<pair<int, int>, pair<int, int>>> q;
void BFS(int a, int b) {
    q.push({{a, b}, {0, 0}});
    visited[a][b][0] = true;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second.first;
        int ability = q.front().second.second;
        q.pop();
        if(x == N && y == M) {
            cout << dist;
            return;
        }
        if(ability < K) {
            for(int i = 0; i < 8; i++) {
                int nx = x + hdx[i];
                int ny = y + hdy[i];
                if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
                if(arr[nx][ny]) continue;
                if(visited[nx][ny][ability + 1]) continue;

                visited[nx][ny][ability + 1] = true;
                q.push({{nx, ny}, {dist + 1, ability + 1}});
            }
        }
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if(arr[nx][ny]) continue;
            if(visited[nx][ny][ability]) continue;

            visited[nx][ny][ability] = true;
            q.push({{nx, ny}, {dist + 1, ability}});
        }

    }
    cout << -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }
    BFS(1, 1);
}