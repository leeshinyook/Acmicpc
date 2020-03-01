//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//#include<algorithm>
//#define RANGE 1000001
//
//using namespace std;
//
//int arr[100001][100001];
//bool visited[100001];
//vector<int> inByOrder;
//vector<int> order;
//int N;
//void DFS(int s) {
//    visited[s] = true;
//    for(int i = 1; i <= N; i++) {
//        if(arr[s][i] == 1 && !visited[i]) {
//            inByOrder.push_back(i);
//            DFS(i);
//        }
//    }
//}
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cin >> N;
//    for(int i = 0; i < N - 1; i++) {
//        int x, y;
//        cin >> x >> y;
//        arr[x][y] =  arr[y][x] = 1;
//    }
//    for(int i = 0; i < N; i++) {
//        int num;
//        cin >> num;
//        order.push_back(num);
//    }
//    inByOrder.push_back(1);
//    for(int i = 1; i <= N; i++) {
//        if(!visited[i]) {
//            DFS(i);
//        }
//    }
//    for(int i = 0; i < N; i++) {
//        if(order[i] != inByOrder[i]) {
//            cout << 0;
//            return 0;
//        }
//    }
//    cout << 1;
//    return 0;
//}
//// cin 과 scanf를 혼용하지 말라. => 에러 발생.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
vector<vector<int>> a;
vector<int> cand;
vector<int> order;
bool check[100001];
void dfs(int x,vector<int>& picked)
{
    if (check[x]) return;

    picked.push_back(x);
    check[x] = true;

    for (int y : a[x]) {
        if (check[y] == false)
            dfs(y,picked);
    }
}
bool compare(int a, int b)
{
    return order[a] < order[b];
}
int main()
{
    cin >> n;
    a = vector<vector<int>>(n, vector<int>());
    cand = vector<int>(n);
    order = vector<int>(n);

    for (int i = 0; i < n - 1; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        n1 -= 1; n2 -= 1;
        a[n1].push_back(n2);
        a[n2].push_back(n1);
    }

    for (int i = 0; i < n; ++i) {
        cin >> cand[i];
        cand[i] -= 1;
        order[cand[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end(), compare);
    }

    vector<int> picked;
    dfs(0,picked);
    for (int i = 0; i < picked.size(); i++)
    {
        if (picked[i] != cand[i]) {
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << 1 << "\n";
    return 0;

}