#include <iostream>
#include <vector>
#include <algorithm>

#define FASTSTD ios::sync_with_stdio(0)
#define FASTCIN cin.tie(0)
using namespace std;

int n, m;
bool check = false;
vector<int> permutation;
bool chosen[1000000];
void search() {
    if(permutation.size() == m) {
        for(int i = 0; i < m - 1; i++) {
            if(permutation[i] > permutation[i + 1]) {
                check = true;
            }
        }
        if(!check) {
            for(int i = 0; i < m; i++) {
                cout << permutation[i] << " ";
            }
            cout << "\n";
        }
        check = false;
    } else {
        for(int i = 1; i <= n; i++) {
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
int main() {
    FASTSTD;
    FASTCIN;
    cin >> n >> m;
    search();
    return 0;
}