#include <iostream>
#include <vector>
#include <algorithm>

#define FASTSTD ios::sync_with_stdio(0)
#define FASTCIN cin.tie(0)
using namespace std;

vector<int> permutation;
int n;
void search(int k);
int main() {
    FASTSTD;
    FASTCIN;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        permutation.push_back(i);
    }
    do {
        for(int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
        }
        cout << '\n';
    } while(next_permutation(permutation.begin(), permutation.end()));
    return 0;
}

