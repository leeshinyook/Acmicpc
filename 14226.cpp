#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
using namespace std;
queue<pair<pair<int, int>, int>> q;
int visited[1001][1001];
int N;
void BFS() {
    q.push({{1, 0}, 0});
    visited[1][0] = 0;
    while(!q.empty()) {
        int emoji = q.front().first.first;
        int clip = q.front().first.second;
        int time = q.front().second;
        if(emoji == N) {
            cout << time;
            return;
        }
        q.pop();
        if(0 < emoji && emoji < 1001) {
            if(!visited[emoji][emoji]) {
                visited[emoji][emoji] = true;
                q.push({{emoji, emoji}, time + 1});
            }
            if(clip >0 && emoji + clip < 1001) {
                if(!visited[emoji + clip][clip]) {
                    visited[emoji + clip][clip] = true;
                    q.push({{emoji + clip, clip}, time + 1});
                }
            }
            if(!visited[emoji - 1][clip]) {
                visited[emoji - 1][clip] = true;
                q.push({{emoji - 1, clip}, time + 1});
            }
        }

    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    BFS();

}

