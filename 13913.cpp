#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int N, K;
int visited[100001];
int M = 98765432;
vector<int> path;
int route [100001];// 경로를 표시한다. s -> e

void BFS(int s) {
    queue<pair<int, int>> q;
    q.emplace(s, 0);
    visited[s] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(x > 100000) continue;
        if(x == K) {
            int idx = x;
            while(idx != N) {
                path.push_back(idx);
                idx = route[idx];
            }
            path.push_back(N);
            if(dist <= M) {
                M = dist;
            }
            return;
        }
        if(0 <= x - 1 && !visited[x - 1]) {
            q.emplace(x - 1, dist + 1);
            visited[x - 1] = true;
            route[x - 1] = x;
        }
        if(x + 1<= 100000 && !visited[x + 1]) {
            q.emplace(x + 1, dist + 1);
            visited[x + 1] = true;
            route[x + 1] = x;
        }
        if(2 * x <= 100000 && !visited[2 * x]) {
            q.emplace(2 * x, dist + 1);
            visited[x * 2] = true;
            route[2 * x] = x;
        }
    }
}
int main() {
    cin >> N >> K;
    BFS(N);
    cout << M << endl;
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }

}
