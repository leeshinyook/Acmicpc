
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
using namespace std;

vector<pair<int, int>> v[100001];
int N;
bool visited[100001];
int ans = 0, maxIdx;
void DFS(int s, int dist) {
    visited[s] = true;
    for(auto x : v[s]) {
        if(visited[x.first]) continue;
        visited[x.first] = true;
        DFS(x.first, dist + x.second);
        visited[x.first] = false;
    }
    if(dist > ans) {
        ans = dist;
        maxIdx = s;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> num;
        while(1) {
            int f, s;
            cin >> f;
            if(f == -1) break;
            else {
                cin >> s;
                v[num].push_back({f, s});
            }
        }
    }
    DFS(1, 0);
    memset(visited, false, sizeof(visited));
    DFS(maxIdx, 0);
    cout << ans;


}