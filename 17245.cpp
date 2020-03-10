#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001][1001];
int N, MAX = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    long long sum = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if(arr[i][j]){
                sum += arr[i][j];
                if(MAX < arr[i][j]) MAX = arr[i][j];
            }
        }
    }
    long long half = (sum + 1) >> 1;
    int left = 0;
    int right = MAX;
    while(left <= right) {
        int mid = (left + right) / 2;
        long long s = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                s += min(mid, arr[i][j]);
            }
        }
        if(s < half) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << left;
}