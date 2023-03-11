#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> arr;

void input() {
    cin>>n;
    int k;
    for(int i=0; i<n; i++) {
        cin>>k;
        arr.push_back(k);
    }
}

void solution() {
    sort(arr.begin(), arr.end());
    int answer = 1;
    for(int i=0; i<n; i++) {
        if(arr[i]>answer) {
            break;
        }
        answer += arr[i];
    }
    cout<<answer;
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
