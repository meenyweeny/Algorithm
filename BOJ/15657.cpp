#include<iostream>
#include<vector>
using namespace std;

int n,m;
int arr[10];

void input() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
}

void solution(vector<int> v,int start) {
    if(v.size()==m) {
        for(auto i:v) {
            cout<<i<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=start; i<n; i++) {
        v.push_back(arr[i]);
        solution(v,i);
        v.pop_back();
    }
}

void solve() {
    input();
    sort(arr, arr+n);
    vector<int> vv;
    solution(vv,0);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
