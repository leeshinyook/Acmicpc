//
// Created by 이신육 on 08/02/2020.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans = 0;
vector<int> permutation;
bool chosen[10000];
int arr[100];
void search() {
    if(permutation.size() == n) {
        int sum = 0;
        for(int i = 0; i < n - 1; i++) {
            sum += abs(permutation[i] - permutation[i + 1]);
        }
        if(ans < sum) ans = sum;
        sum = 0;
    } else {
        for(int i = 1; i <= n; i++) {
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(arr[i]);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    search();
    cout << ans;
}