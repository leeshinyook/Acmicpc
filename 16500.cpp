#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

string Target;
int T_size;
int T;
vector<string> str;
bool joinString(int idx) {
    if(idx == T_size) return true;
    for(auto A: str) {
        bool flag = true;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != Target[idx + i]) flag = false;
        }
        if (flag) {
            if (joinString(idx + A.size())) return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> Target;
    T_size = Target.size();
    cin >> T;
    for(int i = 0; i < T; i++) {
        string string;
        cin >> string;
        str.push_back(string);
    }

    if(joinString(0)) {
        cout << 1;
    } else {
        cout << 0;
    }

}