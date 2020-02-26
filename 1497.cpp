#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include <utility>
#include <tuple>
#include <list>
#include <queue>

using namespace std;

vector<pair<string, string>> v;
vector<pair<string, string>> arr;
vector<string> temp(20);
vector<int> scoreTest(51); // 얼마나 연주할 수 있는지 체크
vector<pair<int, int>> ans;
int N, M;
bool checker = false;
void init() {
    for(int i = 0; i < 51; i++) {
        scoreTest[i] = 0;
    }
}
int findOne() {
    int cnt = 0;
    for(int i = 0; i < 51; i++) {
        if(scoreTest[i] == 1) {
            cnt++;
        }
    }
    return cnt;
}
void search(int k) {
    if(k == N + 1) {
        checker = false;
        for(int i = 0; i < arr.size(); i++) {
            if(temp[i] == arr[i].first) {
                checker = true;
            } else {
                checker = false;
                break;
            }
        }
        if(!checker) {
            init();
            for(int i = 0; i < arr.size(); i++) {
                temp[i] = arr[i].first;
                for(int j = 0; j < M; j++) {
                    if((arr[i].second)[j] == 'Y' || scoreTest[j] == 1) {
                        scoreTest[j] = 1;
                    } else {
                        scoreTest[j] = 0;
                    }
                }
            }
            if(arr.size() == 0 || arr.size() == 1) {

            } else {
                ans.push_back({arr.size() - 1, findOne()});
            }

        }
    } else {
        arr.push_back(v[k]);
        search(k + 1);
        arr.pop_back();
        search(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string guital;
        string score;
        cin >> guital >> score;
        v.push_back({guital, score});
    }
    search(0);

    int MAX = 0;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        if(MAX <= ans[i].second) {
            MAX = ans[i].second;
        }
    }
    if(MAX == 0) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < ans.size(); i++) {
        if(MAX == ans[i].second) {
            answer = ans[i].first;
            break;
        }
    }
    cout << answer;
    return 0;
}
