#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
using namespace std;

vector<int> v;
bool visited[201][201][201];
int A, B, C;
queue<pair<pair<int, int>,int>> q;
void search() {
    q.push({{0, 0}, C});

    while(!q.empty()) {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();
        if(visited[a][b][c]) continue;
        visited[a][b][c] = true;
        if(a == 0) v.push_back(c); // a가 0일때,

        if(a + b > B) q.push({{a + b - B, B}, c}); // A to B
        else q.push({{0, a + b}, c});

        if(a + c > C) q.push({{a + c - C, b}, C}); // A to C
        else q.push({{0, b}, a + c});

        if(b + a > A) q.push({{A, a + b - A}, c}); // B to A
        else q.push({{a + b, 0}, c});

        if(b + c > C) q.push({{a, b + c - C}, C}); // B to C
        else q.push({{a, 0}, b + c});

        if(c + a > A) q.push({{A, b}, c + a - A}); // C to A
        else q.push({{c + a, b}, 0});

        if(c + b > B) q.push({{a, B}, c + b - B}); // C to B
        else q.push({{a, b + c}, 0});
    }
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> C;
    search();
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}