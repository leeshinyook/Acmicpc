#include <iostream>
#include <vector>
using namespace std;

int arr[51][51];
int N, M;
int ans = 1;
void search(int x, int y, int i) {
    bool checker = false;
    if(x + i > N || y + i > M) return;
    int num = arr[x][y];
    if(num != arr[x + i][y]) {
        checker = true;
    }
    if(num != arr[x][y + i]) {
        checker = true;
    }
    if(num != arr[x + i][y + i]) {
        checker = true;
    }

    if(!checker) {
        if(ans < i + 1) ans = i + 1;
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    int L;
    if(N >= M) {
        L = N;
    } else {
        L = M;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            for(int k = 1; k <= L; k++) {
                search(i, j, k);
            }
        }
    }
    search(1, 3, 2);
    cout << ans * ans;
}