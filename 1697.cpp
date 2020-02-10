#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define N 100001
using namespace std;

int visited[100000];
int K, T, V, dist;

queue<pair<int, int>> q;
void BFS(int s) {
    int s1, s2, s3;
    q.push({s, 0});
    visited[s] = true;
    while(!q.empty()) {
        V = q.front().first;
        dist = q.front().second;
        q.pop();
        for(int i = 0; i < 3; i++) {
            s1 = V + 1;
            s2 = V - 1;
            s3 = V * 2;
            if (0 <= s1 && s1 < N && !visited[s1]) {
                visited[s1] = true;
                if (s1 == T) {
                    return;
                }
                q.push({s1, dist + 1});
            }
            if (0 <= s2 && s2 < N && !visited[s2]) {
                visited[s2] = true;
                if (s2 == T) {
                    return;
                }
                q.push({s2, dist + 1});
            }
            if (0 <= s3 && s3 < N && !visited[s3]) {
                visited[s3] = true;
                if (s3 == T) {
                    return;
                }
                q.push({s3, dist + 1});
            }
        }
    }
}
int main() {
    cin >> K >> T;
    if(K == T) {
        cout << 0;
        return 0;
    } else {
        BFS(K);
    }
    cout << dist + 1;
}