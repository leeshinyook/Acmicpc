#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
int node[100001];
int N;
void search(int s) {
    for(auto u : adj[s]) {
        if(!node[u]) {
            node[u] = s; // 부모픽
            search(u);
        }
    }
}
int main() {
//    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int S, E;
        cin >> S >> E;
        adj[S].push_back(E);
        adj[E].push_back(S);
    }
    for(int i = 1; i <= N; i++) {
    }
    search(1);

    for(int i = 2;i <= N; i++) {
        cout << node[i] << "\n";
    }
}