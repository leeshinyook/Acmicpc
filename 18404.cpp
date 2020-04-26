#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int M, N;
int tarX, tarY;
int getX, getY;
bool visited[501][501];
int arr[501][501];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
queue<pair<int, pair<int, int>>> q;
void BFS(int a, int b) {
    q.push({0, {a, b}});
    visited[a][b] = true;
    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int dist = q.front().first;
        q.pop();
        for(int i = 0; i < 8; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx < 1 || mx > N || my < 1 || my > N) continue;
            if(visited[mx][my]) continue;
            visited[mx][my] = true;
            arr[mx][my] = dist + 1;
            q.push({dist + 1, {mx, my}});
        }
    }
}
void Init() {
    while(!q.empty()) q.pop();
    memset(visited, false, sizeof(visited));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    cin >> tarX >> tarY;
    BFS(tarX, tarY);
    while(M--) {
        cin >> getX >> getY;
        cout << arr[getX][getY] << " ";
    }

}
