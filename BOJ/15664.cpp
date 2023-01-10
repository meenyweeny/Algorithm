#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n,m;
int arr[10];
set<string> s;

void input() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
}

void solution(int start, vector<int> v,string ans) {
    if(v.size()==m) {
        if(s.insert(ans).second) {
            for(auto i:v) {
                cout<<i<<' ';
            }
            cout<<'\n';
        }
        return;
    }

    for(int i=start+1; i<n; i++) {
        v.push_back(arr[i]);
        solution(i,v,ans+" "+to_string(arr[i]));
        v.pop_back();
    }
}

void solve() {
    input();
    sort(arr,arr+n);
    for(int i=0; i<n; i++) {
        solution(i-1,{},"");
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
