#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int arr[101][101];
bool visited[101][101];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int N, M;
vector<int> ans;

queue<pair<int, int>> q;

void BFS(int x, int y) {
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()) {
        int mx = q.front().first;
        int my = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int lx = dx[i] + mx;
            int ly = dy[i] + my;
            if(lx < 1 || lx > N || ly < 1 || ly > M) continue;
            if(visited[lx][ly]) continue;
            visited[lx][ly] = true;
            if(arr[lx][ly] == 1 && arr[mx][my] == 0) {
                arr[lx][ly] = 0;
            } else {
                q.push({lx, ly});
            }
        }
    }
}
void init() { // 초기화
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            visited[i][j] = false;
        }
    }
    while(!q.empty()) {
        q.pop();
    }
}
int findCheese() {
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j]) cnt++;
        }
    }
    return cnt;
}
int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
                cin >> arr[i][j];
        }
    }
    while(true) {
        int cheese = findCheese();
        ans.push_back(cheese);
        BFS(1, 1);
        if(cheese == 0) break;
        init();
    }
    cout << ans.size() - 1 << '\n';
    cout << ans[ans.size() - 2];


}

