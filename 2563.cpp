#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[500][500];
int N, M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N >> M;
        for(int j = N; j < N + 10; j++) {
            for(int k = M; k < M + 10; k++) {
                arr[j][k] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < 500; i++) {
        for(int j = 0; j < 500; j++) {
            if(arr[i][j]) cnt++;
        }
    }
    cout << cnt;

}