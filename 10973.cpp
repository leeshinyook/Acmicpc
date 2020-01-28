#include <iostream>
#include <vector>
#include <algorithm>

#define FASTSTD ios::sync_with_stdio(0)
#define FASTCIN cin.tie(0)
using namespace std;

vector<int> permutation;
int n, num;
int cnt = 0;
bool check = false;
int main() {
    FASTSTD;
    FASTCIN;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> num;
        permutation.push_back(num);
    }
    do {
        if(cnt == 1) {
            for(int i = 0; i < n; i++) {
                cout << permutation[i] << " ";
            }
            check = true;
        }
        cnt++;
        if(check) break;
    } while(prev_permutation(permutation.begin(), permutation.end()));
    if(!check) cout << -1;
    return 0;
}

