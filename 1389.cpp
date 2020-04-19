#include <iostream>
#include <climits>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int ans = INT_MAX;
int ans_idx = 0;
vector<int> v[101];
bool visited[101];
int N, M;
void BFS(int a) {
    int sum = 0;
    queue<pair<int, int>> q;
    q.push({a, 1});
    while(!q.empty()) {
        int x = q.front().first;
        int dist = q.front().second;
        q.pop();
        for(auto u : v[x]) {
            if(visited[u]) continue;
            visited[u] = true;
            sum += dist;
            q.push({u, dist + 1});
        }

    }
    if(ans > sum) {
        ans = sum;
        ans_idx = a;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        BFS(i);
    }
    cout << ans_idx;

}
