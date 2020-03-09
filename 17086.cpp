#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int arr[51][51];
int dist[51][51];
bool visited[51][51];
int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
int dy[8] = {1, 0, 0, -1, 1, -1, 1, -1};

int N, M;
int MAX = 9876532;
int MIN = 0;
vector<pair<int, int>> shark;
queue<pair<int, int>> q;

void BFS(int x, int y) {
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()) {
        int mx = q.front().first;
        int my = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++) {
            int lx = dx[i] + mx;
            int ly = dy[i] + my;
            if(lx < 1 || lx > N || ly < 1 || ly > M) continue;
            if(visited[lx][ly]) continue;
            dist[lx][ly] = dist[mx][my] + 1;
            visited[lx][ly] = true;
            q.push({lx, ly});
        }
    }
}
void init() { // 초기화
    for(int i = 0; i < 51; i++) {
        for(int j = 0; j < 51; j++) {
            visited[i][j] = false;
            dist[i][j] = 0;
        }
    }
    while(!q.empty()) {
        q.pop();
    }
}
void findMin() {
    MAX = 9999999;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j]) {
                if(dist[i][j] < MAX) {
                    MAX = dist[i][j];
                }

            }
        }
    }
}
void findMax() {
    if(MAX > MIN) {
        MIN = MAX;
    }
}
int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];

        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j] == 0) {
                BFS(i, j);
                findMin();
                findMax();
                init();
            }
        }
    }

    cout << MIN;
}
