#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int T, MAX = 0;
int length[2001] = {0,};
vector<int> arr(2001);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < T; i++) {
        length[i] = 1;
        for(int j = 0; j <= i; j++) {
            if(arr[j] > arr[i]) {
                length[i] = max(length[i], length[j] + 1);
            }
        }
    }
    for(int i = 0; i < T; i++) {
        MAX = max(MAX, length[i]);
    }
    cout << T - MAX;
}