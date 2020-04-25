#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int x1, y1, x2, y2;
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
bool visited[201][201];
queue<pair<int, pair<int, int>>> q;
void BFS(int a, int b) {
    q.push({0, {a, b}});
    visited[a][b] = true;
    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int dist = q.front().first;
        q.pop();
        if(x == x2 && y == y2){
            cout << dist;
            return;
        };
        for(int i = 0; i < 6; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx < 0 || mx >= N || my < 0 || my >= N) continue;
            if(visited[mx][my]) continue;
            visited[mx][my] = true;
            q.push({dist + 1, {mx, my}});
        }
    }
    cout << -1;
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> x1 >> y1 >> x2 >> y2;
     BFS(x1, y1);
};
