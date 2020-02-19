//
// Created by 이신육 on 19/02/2020.
//
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int N;
long long Max = -1000000001, Min = 1000000001;
vector<int> arr;
vector<int> oper; // 1 = +  2 = -  3 = *  4 = /
int num;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        arr.push_back(num);
    }
    for(int i = 0; i < 4; i++) {
        cin >> num;
        while(num--) {
            oper.push_back(i + 1);
        }
    }
    sort(oper.begin(), oper.end());
    do {
        long long ans = arr[0];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N - 1; j++) {
                if(oper[j] == 1) { // +
                    ans += arr[i + 1];
                } else if(oper[j] == 2) { // -
                    ans -= arr[i + 1];
                } else if(oper[j] == 3) { // *
                    ans *= arr[i + 1];
                } else if(oper[j] == 4){ // /
                    ans /= arr[i + 1];
                }
                i++;
            }
        }
        if(Max < ans) Max = ans;
        if(Min > ans) Min = ans;
    } while(next_permutation(oper.begin(), oper.end()));
    cout << Max << "\n";
    cout << Min;
}
