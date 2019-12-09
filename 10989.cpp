#include <iostream>
#include <vector>

using namespace std;

//countSort..
// countsort는 언제 사용하나? >> 수의 범위가 작다면 카운팅 정렬을 이용하여 빠르게 정렬이 가능하다.
int main() {
    int T, num;
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 속도 향상 위해
    cin >> T;
    vector<int> count(10001);


    for(int i = 0; i < T; i++) {
        cin >> num;
        count[num - 1]++;
    }
    for(int i = 0; i < 10001; i++) {
        for(int j = count[i]; j >0; j--) {
            cout << i + 1 << "\n";
        }
    }
}