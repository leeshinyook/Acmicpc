//
// Created by 이신육 on 09/12/2019.
//
#include <iostream>
#include <vector>

using namespace std;
vector<int> room;
vector<int> PushRoomAndFind(vector<int> room, int h, int w, int n) {
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            room.push_back(101 + i + (100 * j));
        }
    }
    cout << room[n - 1] << "\n";
    return room;
}

int main() {
    int H, W, N;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> H >> W >> N;
        PushRoomAndFind(room, H, W, N);
    }
}
