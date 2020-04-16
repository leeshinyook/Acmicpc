#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int N;
int sum = 0;
vector<int> v;
int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    for(int i = N - 1; i >= 0; i--) {
        while(v[i] <= v[i - 1]) {
            v[i - 1]--;
            sum++;
        }
    }
    cout << sum;


}