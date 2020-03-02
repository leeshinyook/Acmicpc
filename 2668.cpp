#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;

int arr[101];
bool visited[101];
int N;
stack<int> map;
vector<int> ans;
// 사이클을 이루는지 체크한다.
void DFS(int s) {
    if(!visited[arr[s]]) {
        visited[arr[s]] = true;
        map.push(arr[s]);
        DFS(arr[s]);
    }
    memset(visited, false, sizeof(visited));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i <= N; i++) {
        DFS(i);
        if(i == map.top()) {
            ans.push_back(map.top());
        }
        while(!map.empty()) {
            map.pop();
        }
    }
    cout << ans.size() << '\n';
    for(unsigned int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}
