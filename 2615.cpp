#include <iostream>
using namespace std;

int arr[21][21]= {0, };
int CrossSearch(int x, int y) {
    int num = arr[x][y];
    bool checker = false;
    for(int i = 1; i < 5; i++) {
        if(num != arr[x + i][y + i]) {
            checker = true;
        }
    }
    if(checker) return 0;
    if(!checker) {
        if(num != arr[x - 1][y - 1] && num != arr[x + 5][y + 5]) return num;
    }
    return 0;
}
int RecrossSearch(int x, int y) {
    int num = arr[x][y];
    bool checker = false;
    for(int i = 1; i < 5; i++) {
        if(num != arr[x + i][y - i]) {
            checker = true;
        }
    }
    if(checker) return 0;
    if(!checker) {
        if(num != arr[x - 1][y + 1] && num != arr[x + 5][y - 5]) return num;
    }
    return 0;
}
int VerticalSearch(int x, int y) {
    int num = arr[x][y];
    bool checker = false;
    for(int i = 1; i < 5; i++) {
        if(num != arr[x][y + i]) {
            checker = true;
        }
    }
    if(checker) return 0;
    if(!checker) {
        if(num != arr[x][y - 1] && num != arr[x][y + 5]) return num;
    }
    return 0;
}
int ReverticalSearch(int x, int y) {
    int num = arr[x][y];
    bool checker = false;
    for(int i = 1; i < 5; i++) {
        if(num != arr[x + i][y]) {
            checker = true;
        }
    }
    if(checker) return 0;
    if(!checker) {
        if(num != arr[x - 1][y] && num != arr[x + 5][y]) return num;
    }
    return 0;
}
int main() {
    for(int i = 1; i <= 19; i++) {
        for(int j = 1; j <= 19; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= 19; i++) {
        for(int j = 1; j <= 19; j++) {
            int x = CrossSearch(i, j);
            int y = RecrossSearch(i, j);
            int z = VerticalSearch(i, j);
            int k = ReverticalSearch(i, j);
            if(x) {
                if(x == 1) {
                    cout << 1 << '\n';
                    cout << i << " " << j ;
                } else {
                    cout << 2 << '\n';
                    cout << i << " " << j ;
                }
                return 0;
            }
            if(y) {
                if(y == 1) {
                    cout << 1 << '\n';
                    cout << i << " " << j ;
                } else {
                    cout << 2 << '\n';
                    cout << i << " " << j ;
                }
                return 0;
            }
            if(z) {
                if(z == 1) {
                    cout << 1 << '\n';
                    cout << i << " " << j ;
                } else {
                    cout << 2 << '\n';
                    cout << i  << " " << j ;
                }
                return 0;
            }
            if(k) {
                if(k == 1) {
                    cout << 1 << '\n';
                    cout << i << " " << j ;
                } else {
                    cout << 2 << '\n';
                    cout << i << " " << j ;
                }
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}