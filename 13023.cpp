#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
vector<int> adj[2001];
bool visited[2001];
int N, M;
bool checker;
void search(int s, int cnt) {
    if(cnt == 4) {
        checker = true;
        return;
    }
    visited[s] = true;
    for(auto u : adj[s]) {
        if(visited[u]) continue;
        search(u, cnt + 1);
        if(checker) return;
    }
    visited[s] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        search(i, 0);
        if(checker) break;
    }
    if(checker) {
        cout << 1;
    } else {
        cout << 0;
    }

}
