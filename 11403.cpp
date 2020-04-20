#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N;
int arr[101][101];
bool visited[101];

void DFS(int x) {
    for(int i = 1; i <= N; i++) {
        if(arr[x][i] && !visited[i]) {
            visited[i] = true;
            DFS(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j<= N; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        DFS(i);
        for(int j = 1; j <= N; j++) {
            if(visited[j]) arr[i][j] = 1;
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
