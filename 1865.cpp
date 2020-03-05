#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

// 벨만-포드 알고리즘
// 다른 모든 노드로 가능 최단 경로를 구하는 알고리즘.

// 입력받은 출발점에서 도착점까지의 최단경로를 출력하십시요.
vector<pair<int, int>> adj[502];
int dist[502];
bool cycle = false;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V, E , S , T; // V : 노드의 개수, E : 엣지의 개수, S: 시작점, T: 끝점
    int a, b, w; // (a, b) = w (가중치);
    int Hall;

    int TC;
    cin >> TC;
    while(TC--) {
        cycle = false;
        cin >> V >> E >> Hall;
//        S = 1;
        T = V;

        for(int i = 0; i < 502; i++) {
            while(!adj[i].empty()) {
                adj[i].pop_back();
            }
        }
        for(int i = 0; i <= V + 1; i++) {
            dist[i] = INF; // 거리도 무한대로 설정.
        }

        for(int j = 0; j < E; j++) {
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        for(int i = 0; i < Hall; i++) {
            cin >> a >> b >> w;
            adj[a].push_back({b, w *  -1});
        }

        dist[1] = 0; // dist배열은 가중치가 저장된다.

        for(int i = 1; i <= V; i++) {
            for(int j = 1; j <= V; j++) {
                for(auto &n : adj[j]) {
                    if(dist[j] != INF && dist[n.first] > n.second + dist[j]) {
                        dist[n.first] = n.second + dist[j];
                        if(i == V) cycle = true;
                    }
                }
            }
        }

        if(cycle) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

//
//    for (int i = 0; i <= T; i++) {
//        if (dist[i] == INF) {
//            cout << "-1" << '\n';
//        } else {
//            cout << dist[i] << '\n';
//        }
//    }

}