#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#define INF INT_MAX

using namespace std;
bool processed[1001];
int dist[1001];
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>> q;
int V, E, S;
int D;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V;
    cin >> E;
    for(int i = 0; i <= 1000; i++) {
        dist[i] = INF;
    }
    for(int i = 0; i < E; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    cin >> S >> D;

    dist[S] = 0;
    q.push({0, S}); // dist, w

    while(!q.empty()) {
        int a = q.top().second;
        q.pop();
        if(processed[a]) continue;
        for(auto u : adj[a]) {
            int b = u.first, w = u.second;
            if(dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
    cout << dist[D];


}