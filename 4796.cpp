#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int L, P, V;
int main() {
    for(int i = 1;; i++) {
        cin >> L >> P >> V;
        if(!L && !P && !V) return 0;
        int a = V / P;
        int ans = 0;
        if(V % P > L) {
            ans += L;
        } else ans += V % P;
        ans += a * L;
        cout << "Case " << i << ": "<< ans << '\n';

    }

}