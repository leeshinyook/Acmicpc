#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<int> v[100001];
bool visited[100001];
queue<pair<int, int>> q;
void BFS(int x) {
    q.push({x, 0});
    visited[x] = true;
    while(!q.empty()) {
        int s = q.front().first;
        int dist = q.front().second;
        if(s == N) {
            cout << dist;
            return;
        }
        q.pop();
        for(auto e : v[s]) {
            if(visited[e]) continue;
            visited[e] = true;
            q.push({e, dist + 1});
        }
    }
    cout << -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    BFS(1);

}