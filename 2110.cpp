#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
int N, C;
int main() {
    cin >> N >> C;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());

    int left = 1; // 가능한 최소 거리
    int right = arr[N - 1] - arr[0]; // 가능한 최대 거리
    int ans = 0, d = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int start = arr[0];
        int cnt = 1;
        // 간격을 기준으로 공유기를 설치한다.
        for(int i = 1; i < N; i++) {
            d = arr[i] - start;
            if(mid <= d) {
                cnt++;
                start = arr[i];
            }
        }
        if(cnt >= C) { // 공유기의 수를 줄인다.
            ans = mid;
            left = mid + 1;
        } else { // 공유기가 더 설치되어야한다.
            right = mid - 1;
        }
    }
    cout << ans;
}
