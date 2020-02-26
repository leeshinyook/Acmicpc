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

vector<int> permutation;
vector<int> temp(10);
vector<int> join(10);
bool chosen[10000];
bool checker = false;
long T, L;
long ans = 0;
int joinNumber(vector<int> a) {
    int sum = 0;
    for(int i = 0; i < L; i++) {
        sum += a[i] * pow(10, L - i - 1);
    }
    while(!a.empty()) {
        a.pop_back();
    }
    return sum;
}
int getLength(long a) {
    long temp = a;
    int len = 0;
    while(temp) {
        temp /= 10;
        len++;
    }
    return len;
}
void search() {
    if(permutation.size() == L) {
        checker = false;
        for(int i = 0; i < L; i++) {
            if(temp[i] == permutation[i]) {
                checker = true;
            } else {
                checker = false;
                break;
            }
        }
        if(!checker) {
            for(int i = 0; i < L; i++) {
                temp[i] = permutation[i];
                join[i] = permutation[i];
            }
            int Min = joinNumber(join) - T;
            if(Min <= 0) {
               long temp =  Min + T;
               if(ans < temp) {
                    ans = temp;
                    return;
               }
            }
        }
    } else {
        for(int i = 9; i >= 0; i--) {
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    L = getLength(T);
    if(L > 10) {
        cout << 9876543210;
        return 0;
    }
    search();
    cout << ans;
}
