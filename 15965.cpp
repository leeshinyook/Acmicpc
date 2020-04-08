#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int arr[7500001];
int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 2; i < 7500001; i++) arr[i] = i;

    for(int i = 2; i < 7500001; i++) {
        if(!arr[i]) continue;
        for(int j = i + i; j <7500001; j += i) {
            arr[j] = 0;
        }
    }
    for(int i = 2; i <= 7500000; i++) {
        if(arr[i]) {
            N--;
            if(N == 0) {
                cout << arr[i];
                break;
            }
        }
    }

}