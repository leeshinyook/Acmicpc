//
// Created by 이신육 on 2020-02-05.
//
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <set>
#include <cstdlib>
#include <cstdio>
using namespace std;

vector<int> num;
vector<int> rule;
int N;
bool checker = false;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        rule.push_back(n);
        num.push_back(i + 1);
    }
    do {
        checker = false;
        for(int i = 0; i < N; i++) {
            int cnt = rule[i]; // 1 부터
            int lcnt = 0;
            for(int j = 0; j < N; j++) {
                if(num[j] == i + 1) {
                    if(lcnt != cnt) {
                        checker = true; // 실패체크
                    }
                } else if (num[j] > i + 1) {
                    lcnt++;
                }
            }
        }
        if(!checker) {
            for(int i = 0; i < N; i++) {
                cout << num[i] << " ";
            }
            break;
        }
    } while(next_permutation(num.begin(), num.end()));
}
