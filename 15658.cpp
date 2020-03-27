#include <iostream>
#include <climits>

using namespace std;

int Max = INT_MIN;
int Min = INT_MAX;
int N;
int arr[11];
int Plus, Minus, Multi, Div;

void DFS(int P, int Mi, int Mu, int Di, int sum, int idx) {
    if(idx == N) {
        if(sum > Max) Max = sum;
        if(sum < Min) Min = sum;
        return;
    }
    if(P < Plus) DFS(P + 1, Mi, Mu, Di, sum + arr[idx], idx + 1);
    if(Mi < Minus) DFS(P, Mi + 1, Mu, Di, sum - arr[idx], idx + 1);
    if(Mu < Multi) DFS(P, Mi, Mu + 1, Di, sum * arr[idx], idx + 1);
    if(Di < Div) DFS(P, Mi, Mu, Di + 1, sum / arr[idx], idx + 1);
}
int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> Plus >> Minus >> Multi >> Div;
    DFS(0, 0, 0, 0, arr[0], 1);
    cout << Max << '\n';
    cout << Min;
}