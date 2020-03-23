#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n, m, sx, sy, inf = 1e9;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int dist[22][22][22][22];
bool check[22][22][22][22];
char map[22][22];
vector<pair<int, int>> vt;
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    check[x][y][x][y] = true;
    dist[x][y][x][y] = 0;
    while (!q.empty()) {
        int ax = q.front().first;
        int ay = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = ax + dx[i];
            int ny = ay + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (!check[nx][ny][x][y] && map[nx][ny] != 'x') {
                    check[nx][ny][x][y] = true;
                    dist[nx][ny][x][y] = dist[ax][ay][x][y] + 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
}
int main() {
    while (scanf(" %d %d", &m, &n) != -1) {
        if (n == 0 && m == 0) return 0;
        memset(check, 0, sizeof(check));
        memset(map, 0, sizeof(map));
        vt.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < m; l++) {
                        dist[i][j][k][l] = inf;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %1c", &map[i][j]);
                if (map[i][j] == 'o') sx = i, sy = j;
                else if (map[i][j] == '*') vt.push_back({ i,j });
            }
        }
        if (vt.size() == 0) {
            puts("0"); continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bfs(i, j);
            }
        }
        int cnt = vt.size();
        int ans = 1e9;
        sort(vt.begin(), vt.end());
        bool ok = true;
        do {
            int temp = dist[vt[0].first][vt[0].second][sx][sy];
            for (int i = 1; i < cnt; i++) temp += dist[vt[i].first][vt[i].second][vt[i - 1].first][vt[i - 1].second];
            if (temp >= 1e9) {
                ok = false; break;
            }
            ans = min(ans, temp);
        } while (next_permutation(vt.begin(), vt.end()));
        if (!ok) puts("-1");
        else printf("%d\n", ans);
    }
}
