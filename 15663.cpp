#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<int> temp(N);
    vector<int> v(N);
    bool checker = false;
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

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
                temp[i] = v[i];
                cout << v[i] << " ";
            }
            cout << "\n";
        }

    } while(next_permutation(v.begin(), v.end()));
}