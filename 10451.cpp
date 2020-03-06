#include <iostream>
#include <vector>
using namespace std;

int arr[1001];
int visited[1001];
int T, M;
int cnt = 0;
void DFS(int x) {
    if(!visited[x]) {
        visited[x] = true;
        DFS(arr[x]);
    }

}
void init() {
    for(int i = 0; i < 1001; i++) {
            visited[i] = false;
            arr[i] = 0;
    }
}
int main() {
    cin >> T;
    while(T--) {
        cin >> M;
        cnt = 0;
        for(int i = 1; i <= M; i++) {
            int num;
            cin >> num;
            arr[i] = num;
        }
        for(int i = 1; i <= M; i++) {
            if(!visited[i]) {
                cnt++;
                DFS(i);
            }
        }
        init();
        cout << cnt << '\n';
    }

}