#include <iostream>
#include <vector>
#include <algorithm>

#define FASTSTD ios::sync_with_stdio(0)
#define FASTCIN cin.tie(0)
using namespace std;

int N, M;
int n;
vector<int> arr(10);
vector<int> permutation;
vector<int> temp(10);
bool checker = false;
void search() {
    if(permutation.size() == M) {
        // 중복 체크
        checker = false;
        for (int i = 0; i < M; i++) {
            if(temp[i] == permutation[i]) {
                checker = true;
            } else {
                checker = false;
                break;
            }
        }
        for (int i = 0; i < M - 1; i++) {
            if(permutation[i] > permutation[i + 1]) {
                checker = true;
                break;
            }

        }
        if(!checker) {
            for (int i = 0; i < M; i++) {
                cout << permutation[i] << " ";
                temp[i] = permutation[i];
            }
            cout << "\n";
        }

    } else {
        for(int i = 0; i < N; i++) {
            if(arr[i] == 0) continue;
            permutation.push_back(arr[i]);
            search();
            permutation.pop_back();
        }


    }
}
int main() {
    FASTSTD;
    FASTCIN;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end() - 10 + N);
    arr.erase(unique(arr.begin(), arr.end() - 10 + N), arr.end() - 10 + N);
    search();
    return 0;
}