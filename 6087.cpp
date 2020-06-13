
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
using namespace std;

char arr[101][101];
int dist[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M;
queue<pair<int,int>> lazer;
queue<pair<int, int>> q;
void BFS() {
    q.push({lazer.front().first, lazer.front().second});
    lazer.pop();
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            while(1 <= mx && mx <= M && 1 <= my && my <= N && arr[mx][my] != '*') {
                if (!dist[mx][my]) { // 0인 경우.
                    dist[mx][my] = dist[x][y] + 1;
                    q.push({mx, my});
                }
                mx += dx[i], my = dy[i];
            }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'C') {
                lazer.push({i, j});
            }
        }
    }
    BFS();
    cout << dist[lazer.front().first][lazer.front().second] - 1;

}


