#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include <utility>
#include <tuple>
#include <list>
#include <queue>

using namespace std;

vector<int> equals; // '<' = 1 '>' = 0
vector<int> num;
int T;
bool checker;
void findMax() {
    vector<int> temp(T + 1);
    do {
        checker = false;
        for(int i = 0; i < T + 1; i++) {
            if(temp[i] == num[i]) {
                checker = true;
            } else {
                checker = false;
                break;
            }
        }
        for(int i = 0; i < T; i++) {
            if(equals[i] == 1) { // <
                if(num[i] > num[i + 1]) {
                    checker = true;
                    break;
                }
            } else { // >
                if(num[i] < num[i + 1]) {
                    checker = true;
                    break;
                }
            }
        }
        if(!checker) {
            for(int i = 0; i < T + 1; i++) {
                temp[i] = num[i];
                printf("%d", num[i]);
            }
            printf("\n");
            return;
        }
    } while(prev_permutation(num.begin(), num.end()));
}
void findMin() {
    vector<int> temp(T + 1);
    do {
        checker = false;
        for(int i = 0; i < T + 1; i++) {
            if(temp[i] == num[i]) {
                checker = true;
            } else {
                checker = false;
                break;
            }
        }
        for(int i = 0; i < T; i++) {
            if(equals[i] == 1) { // <
                if(num[i] > num[i + 1]) {
                    checker = true;
                    break;
                }
            } else { // >
                if(num[i] < num[i + 1]) {
                    checker = true;
                    break;
                }
            }
        }
        if(!checker) {
            for(int i = 0; i < T + 1; i++) {
                temp[i] = num[i];
                printf("%d", num[i]);
            }
            return;
        }
    } while(next_permutation(num.begin(), num.end()));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;

    for(int i = 0; i < T; i++) {
        char command;
        cin >> command;
        if(command == '<') {
            equals.push_back(1);
        } else if(command == '>'){
            equals.push_back(0);
        }
    }
    for(int i = 9; i >= 0; i--) {
        num.push_back(i);
    }
    findMax();
    while(!num.empty()) {
        num.pop_back();
    }
    for(int i = 0; i < 10; i++) {
        num.push_back(i);
    }
    findMin();



}
