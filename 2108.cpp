#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int main() {
    // T is odd
    int T, num;
    int sum = 0, temp;
    int max = 0, idx = 1, count = 0;
    int median, range, mode;
    float avg;

    cin >> T;
    vector<int> v(T);
    vector<pair<int,int>> fr(T);

    if(T == 1) idx = 0;
    for(int i = 0; i < T; i++) {
        cin >> num;
        v[i] = num;

    }
    sort(v.begin(), v.end());
    for(int i = 0; i < T; i++) {
        sum += v[i];
    }
    for(int i = 0; i < T - 1; i++) { // 최빈값구하기 << 고민.
        if(v[i] == v[i + 1]) {
            temp =i;
            count++;
        } else {
            if(count) {
                fr[i].first = temp;
                fr[i].second = ++count;
            }
            count = 0;

        }
        if(max <= count) {
            max = count;

        }
    }
    for(int i = 0; i < fr.size(); i++) {
        cout << fr[i].first << " " << fr[i].second;
    }
    mode = v[idx];
    avg = round(float(sum) / T);
    median = v[T/2];
    range = v[T - 1] - v[0];
    cout << avg << endl;
    cout << median << endl;
    cout << mode << endl;
    cout << range << endl;

}