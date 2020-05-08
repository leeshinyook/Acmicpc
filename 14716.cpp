#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int arr[251][251];
bool visited[251][251];
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int cnt = 0;
queue<pair<int, int>> q;
void BFS(int a, int b) {
    q.push({a, b});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx < 1 || mx > N || my < 1 || my > M) continue;
            if(visited[mx][my]) continue;
            if(!arr[mx][my]) continue;
            visited[mx][my] = true;
            q.push({mx, my});
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j] && !visited[i][j]) {
                BFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}