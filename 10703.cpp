#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, M;
char arr[3001][3001];
int sky[3001];
int land[3001];
int gap = INT_MAX;
void findGap() {
    for(int j = 1; j <= M; j++) {
        if(gap > land[j] - sky[j] && land[j] && sky[j]) gap = land[j] - sky[j];
    }
}
void Set() {
    for(int i = N; i > 0; i--) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j] == 'X') {
                arr[i][j] = '.';
                arr[i + gap][j] = 'X';
            }
        }
    }
}
void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}
int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'X') {
                sky[j] = i;
            }
            if(arr[i][j] == '#'){
                if(!land[j]) {
                    land[j] = i - 1;
                }
            }
        }
    }
    findGap();
    Set();
    Print();
}
