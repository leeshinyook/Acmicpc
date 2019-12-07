#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<pair<int, int>> v(T); // weight, height;
    vector<int> rank(T, 1); // 등수를 담는 벡터 T개의 원소를 1로 초기화한다.

    for(int i = 0; i < T; i++) {
        cin >> v[i].first >> v[i].second;
    }
    // brute force > 2중포문 가능할 것 같다.
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < T; j++) {
            if(v[i].first < v[j].first && v[i].second < v[j].second) { // 나보다 큰수 count
                rank[i]++;
            }
        }
    }
    for(int i = 0; i < T; i++) {
        cout << rank[i] <<" ";
    }




    return 0;
}