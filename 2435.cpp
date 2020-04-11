#include <iostream>
#include <vector>
#include <set>
using namespace std;

int arr[101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int ans = -101;
    for(int i = 0; i <= N - K; i++) {
        int sum = 0;
        for(int j = i; j < i + K; j++) {
            sum += arr[i + j];
        }
        if(ans < sum) ans = sum;

    }
    cout << ans;


}