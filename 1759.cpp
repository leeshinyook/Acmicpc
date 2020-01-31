#include <iostream>
#include <vector>
#include <algorithm>

#define FASTSTD ios::sync_with_stdio(0)
#define FASTCIN cin.tie(0)
using namespace std;
int N, M;
vector<string> v;
vector<string> vp;
vector<string> ans;
bool chosen[100];
bool asending = true;
string vowel = "aeiou";
int vowel_count = 0;
int con_count = 0;
void init() {
    vowel_count = 0;
    con_count = 0;
    asending = true;
}
void search() {
    if(vp.size() == N) {
        for(int i = 0; i < N - 1; i++) {
            if(vp[i].compare(vp[i + 1]) > 0) {
                asending = false;
            }
        }
        for(int i = 0; i < N; i++) {
            if (vowel.find(vp[i]) != string::npos) {
                vowel_count++;
            } else {
                con_count++;
            }
        }
        if(asending && vowel_count > 0 && con_count > 1) {
            string an = "";
            for(int i = 0; i < N; i++) {
                an += vp[i];
            }
            ans.push_back(an);
        }
        init();
    } else {
        for(int i = 0; i < M; i++) {
            if(chosen[i]) continue;
            chosen[i] = true;
            vp.push_back(v[i]);
            search();
            chosen[i] = false;
            vp.pop_back();
        }
    }
}

int main() {
    FASTSTD;
    FASTCIN;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    search();
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}