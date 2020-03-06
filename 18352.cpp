#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> adj[300001], ans;
bool visited[300001];
int N, M, K, X;
void BFS() {
    queue<pair<int, int>> q;
    q.emplace(X, 0);
    while(!q.empty()) {
        int x = q.front().first;
        int val = q.front().second;
        q.pop();
        if(visited[x]) continue;
        visited[x] = true;
        if(val == K) {
            ans.push_back(x);
        }
        for(auto i : adj[x]) {
            if(visited[i]) continue;
            q.emplace(i, val + 1);
        }
    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K >> X;
    for(int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        adj[S].push_back(E);
    }
    BFS();
    sort(ans.begin(), ans.end());
    if(!ans.size()) {
        cout << -1;
        return 0;
    }
    for(auto s : ans) {
        cout << s << '\n';
    }

}