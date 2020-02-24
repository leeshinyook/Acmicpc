#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(10);
vector<int> temp(10);
int N, M;
bool checker = false;
int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end() - 10 + N);
    do {
        checker = false;
        for(int i = 0; i < M; i++) {
            if(temp[i] == v[i]) {
                checker = true;
            } else {
                checker = false;
                break;
            }
        }
        if(!checker) {
            for(int i = 0; i < M; i++) {
                cout << v[i] << " ";
                temp[i] = v[i];
            }
            cout << '\n';
        }
    } while(next_permutation(v.begin(), v.end() - 10 + N));
}

