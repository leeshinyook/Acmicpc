#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int A, B, N, M;
bool visited[100001];
int dist[100001];
queue<int> q;
void Search(int pos) {
    q.push(pos);
    visited[pos] = true;
    while(!q.empty()) {
        int x = q.front();
        if(x == M) return;
        q.pop();
        if(x + 1 >= 0 && x + 1 <= 100000 && !visited[x + 1]) {
            visited[x + 1] = true;
            dist[x + 1] = dist[x] + 1;
            q.push(x + 1);
        }
        if(x - 1 >= 0 && x - 1 <= 100000 && !visited[x - 1]) {
            visited[x - 1] = true;
            dist[x - 1] = dist[x] + 1;
            q.push(x - 1);
        }
        if(A * x >= 0 && A * x <= 100000 && !visited[A * x]) {
            visited[A * x] = true;
            dist[A * x] = dist[x] + 1;
            q.push(A * x);
        }
        if(x + A >= 0 && x + A <= 100000 && !visited[A + x]) {
            visited[A + x] = true;
            dist[A + x] = dist[x] + 1;
            q.push(A + x);
        }
        if(x - A >= 0 && x - A <= 100000 && !visited[x - A]) {
            visited[x - A] = true;
            dist[x - A] = dist[x] + 1;
            q.push(x - A);
        }
        if(B * x >= 0 && B * x <= 100000 && !visited[B * x]) {
            visited[B * x] = true;
            dist[B * x] = dist[x] + 1;
            q.push(B * x);
        }
        if(x + B >= 0 && x + B <= 100000 && !visited[x + B]) {
            visited[B + x] = true;
            dist[B + x] = dist[x] + 1;
            q.push(B + x);
        }
        if(x - B >= 0 && x - B <= 100000 && !visited[x - B]) {
            visited[x - B] = true;
            dist[x - B] = dist[x] + 1;
            q.push(x - B);
        }

    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> N >> M;
    Search(N);
    cout << dist[M];
}