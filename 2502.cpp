#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> v(50);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    v[1].first = 1;
    v[1].second = 0;
    v[2].first = 0;
    v[2].second = 1;
    for(int i = 3; i <= 30; i++) {
        v[i].first = v[i - 1].first + v[i - 2].first;
        v[i].second = v[i - 1].second + v[i - 2].second;
    }
    bool checker = false;
    int x, y;
    for(int i = 1;; i++) {
        if(checker) {
            break;
        }
        for(int j = i;; j++) {
            int num = v[N].first * i + v[N].second * j;
            if(M == num) {
                x = i;
                y = j;
                checker = true;
                break;
            };
            if(num > M)break;
        }
    }
    cout << x << '\n';
    cout << y;




    return 0;
}
