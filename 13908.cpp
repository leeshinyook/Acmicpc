#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cstring>
#include<stack>
#include<math.h>
#include<algorithm>

using namespace std;

vector<int> permutation;
vector<bool> visited(10);
vector<bool> vis(10);
int N, M;
int cnt = 0;
int checker = 0;
void search() {
    if(permutation.size() == N) {
        checker = 0;
        for(int i = 0; i < 10; i++) {
            vis[i] = false;
        }
        for(int i = 0; i < N; i++) {
            if(visited[permutation[i]] && !vis[permutation[i]]) {
                checker++;
                vis[permutation[i]] = true;
                if(checker == M) {
                    cnt++;
                    break;
                }
            }
        }
    } else {
        for(int i = 0; i < 10; i++) {
            permutation.push_back(i);
            search();
            permutation.pop_back();
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    if(M == 0) {
        if(N == 0) {
            cout << 0;
            return 0;
        }
        cout << pow(10, N);
        return 0;
    }
    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        visited[num] = true;
    }
    search();

    cout << cnt;
}
