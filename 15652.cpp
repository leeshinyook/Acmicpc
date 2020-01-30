#include <iostream>
#include <vector>
#include <algorithm>

#define FASTSTD ios::sync_with_stdio(0)
#define FASTCIN cin.tie(0)
using namespace std;

vector<int> permutation;
int M, N;
bool checker = false;
void search() {
    if(permutation.size() == N) {
        for(int i = 0 ; i < N - 1; i++) {
            if(permutation[i] > permutation[i + 1]) {
                checker = true;
            }
        }
        if(!checker) {
            for(int i = 0; i < N; i++) {
                cout << permutation[i] << " ";
            }
            cout << "\n";
        }
        checker = false;
    } else {
        for(int i = 1; i <= M; i++) {
            permutation.push_back(i);
            search();
            permutation.pop_back();
        }
    }

}
int main() {
    FASTSTD;
    FASTCIN;
    cin >> M >> N;

    search();


    return 0;
}