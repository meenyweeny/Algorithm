#include<iostream>
#include<vector>
using namespace std;

int n,m;
int arr[10];
vector<int> ans;

void input() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
}

void solution(vector<int> v) {
    if(v.size()==m) {
        if(v.back()!=ans.back()) {
            ans = v;
            for(auto i:v) {
                cout<<i<<' ';
            }
            cout<<'\n';
        }
        return;
    }

    for(int i=0; i<n; i++) {
        if(i!=0 && arr[i-1]==arr[i]) {
            continue;
        }
        v.push_back(arr[i]);
        solution(v);
        v.pop_back();
    }
}

void solve() {
    input();
    sort(arr,arr+n);
    ans.push_back(-1);
    solution({});
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
