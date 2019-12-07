#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool compare(const pair<int, int> a, const pair<int, int> b) {
    if(a.second == b.second) { // 빈도가 같으면
        return a.first < b.first; // 키값이 작은게 앞으로 온다
    }
    return a.second > b.second;
}
int main() {
    // T is odd
    int T, num;
    int sum = 0;
    int idx = 1, count = 0;
    int median, range, mode;
    float avg;

    cin >> T;
    vector<int> v(T);
    vector<pair<int, int>> fv; // key와 빈도수를 저장하는 벡터페어
    if(T == 1) idx = 0;
    for(int i = 0; i < T; i++) {
        cin >> num;
        v[i] = num;

    }
    sort(v.begin(), v.end()); // 오름차순 정렬
    for(int i = 0; i < T; i++) {
        sum += v[i];
    }
    for(int i = 0; i < T - 1; i++) { // 최빈값구하기
        if(fv.empty()) {
            fv.push_back(pair<int, int>(v[i], i));
        }
        if(v[i] == v[i + 1]) {
            fv.pop_back();
            count++;
            fv.push_back(pair<int, int>(v[i], count));
        } else {
            count = 0;
            fv.push_back(pair<int, int>(v[i + 1], 0));
        }
    }
    if(T > 1) {
        sort(fv.begin(), fv.end(), compare);
        if(fv[0].second == fv[1].second) {
            mode = fv[1].first;
        } else {
            mode = fv[0].first;
        }
    } else {
        mode = v[idx];
    }
    avg = round(float(sum) / T);
    median = v[T/2];
    range = abs(v[T - 1] - v[0]);
    cout << avg << endl;
    cout << median << endl;
    cout << mode << endl;
    cout << range << endl;
}