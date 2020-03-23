#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

char arr[21][21];
int dist[21][21];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int M, N;
bool visited[21][21];
vector<pair<int, int>> dirt;
struct Robot {
    int x, y;
};
Robot robot;
queue<pair<int, int>> q;
int BFS(int a, int b) {
    q.push({a, b});
    visited[a][b] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int mx = dx[i] + x;
            int my = dy[i] + y;
            if (mx < 1 || mx > M || my < 1 || my > N) continue;
            if(arr[mx][my] == 'x') continue;
            if(visited[mx][my]) continue;
            visited[mx][my] = true;
            dist[mx][my] = dist[x][y] + 1;
            q.push({mx, my});
        }
    }
}
void print() {
    for(int i = 1;i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}
void init() {
    while(!q.empty()) q.pop();
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 21; j++) {
            dist[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        cin >> N >> M;
        if(N == 0 && M == 0) return 0;

        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                cin >> arr[i][j];
                if(arr[i][j] == 'o') {
                    robot.x = i;
                    robot.y = j;
                }
                if(arr[i][j] == '*') {
                    dirt.push_back({i, j});
                }
            }
        }
        BFS(robot.x, robot.y);
        for(int i = 0; i < dirt.size(); i++) {

        }
        for(int i = 0; i < dirt.size(); i++) {
            if(dist[dirt[i].first][dirt[i].second] == 0) {
                cout << -1;
                return 0;
            }
        }
        sort(dirt.begin(), dirt.end());
        vector<int> vt;
        for(int i = 0; i < dirt.size(); i++) {
            vt.push_back(i);
        }
        int sum = INT_MAX;
        int ans = 0;
        do {
            for(int i = 0; i < vt.size(); i++) {
                ans += dist[dirt[vt[i]].first][dirt[vt[i]].second];
                init();
                BFS(dirt[vt[i]].first, dirt[vt[i]].second);
//                cout << dirt[i].first << " " << dirt[i].second << "   ";
//                cout <<vt[i] << " ";
            }
//            cout << '\n';
            if(sum > ans) sum = ans;

            ans = 0;
            init();
            BFS(robot.x, robot.y);
        } while(next_permutation(vt.begin(), vt.end()));
        cout << sum << '\n';
        while(!dirt.empty()) {
            dirt.pop_back();
        }
//        init();
//        for(int i = 0; i < 21; i++) {
//            for(int j = 0; j < 21; j++) {
//                arr[i][j] = 0;
//            }
//        }
        memset(arr, 0, sizeof(arr));
//        memset(dist, 0, sizeof(dist));
    }

}