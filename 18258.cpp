#include <iostream>
#include <queue>
#include <cstring>
char word[10];

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    int T;
    int a;
    cin >> T;
    queue<int> q;
    for(int i = 0; i < T; i++) {
        cin >> word;
        if(!strcmp(word, "push")) {
            cin >> a;
            q.push(a);
        } else if(!strcmp(word, "pop")) {
            if (!q.size()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if(!strcmp(word, "front")) {
            if(!q.size()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
            }
        } else if(!strcmp(word, "back")) {
            if(!q.size()) {
                cout << - 1 << '\n';
            } else {
                cout << q.back() << '\n';
            }
        } else if(!strcmp(word, "size")) {
            cout << q.size() << '\n';
        } else if(!strcmp(word, "empty")) {
            cout << q.empty() << '\n';
        }
    }
}