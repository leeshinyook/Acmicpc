#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include <utility>
#include <tuple>
#include <list>
#include <queue>

using namespace std;

vector<int> arr;
vector<int> temp(10);
vector<int> permutation(10);
int M, N;
bool checker = false;
void search() {
    if(arr.size() == N) {
        checker = false;
        for(int i = 0; i < N; i++) {
            if(temp[i] == arr[i]) {
                checker = true;
            } else {
                checker = false;
                break;
            }
        }
        if(!checker) {
            for(int i = 0; i < N; i++) {
                cout << arr[i] << " ";
                temp[i] = arr[i];
            }
            cout << '\n';
        }
    } else {
        for(int i = 0; i < M; i++) {
            arr.push_back(permutation[i]);
            search();
            arr.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        cin >> permutation[i];
    }
    sort(permutation.begin(), permutation.end() - 10 + M);
    search();

}
