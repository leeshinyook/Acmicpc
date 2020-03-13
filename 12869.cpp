#include <iostream>
#include <queue>

using namespace std;
int MIN = 987654;
int N;
int scv[3];
void search(int scv1, int scv2, int scv3, int dist) {
    if(scv1 <= 0 && scv2 <= 0 && scv3 <= 0) {
        if(dist < MIN) {
            MIN = dist;
        }
        return;

    }
    if(scv1 >= scv2 && scv1 >= scv3) {
        search(scv1 - 9, scv2 - 3, scv3 - 1, dist + 1);
        search(scv1 - 9, scv2 - 1, scv3 - 3, dist + 1);
    }
    if(scv2 >= scv1 && scv2 >= scv3) {
        search(scv1 - 3, scv2 - 9, scv3 - 1, dist + 1);
        search(scv1 - 1, scv2 - 9, scv3 - 3, dist + 1);
    }
    if(scv3 >= scv2 && scv3 >= scv1) {
        search(scv1 - 1, scv2 - 3, scv3 - 9, dist + 1);
        search(scv1 - 3, scv2 - 1, scv3 - 9, dist + 1);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> scv[i];
    }
    search(scv[0], scv[1], scv[2], 0);
    cout << MIN;
}
