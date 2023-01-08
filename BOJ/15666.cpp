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

void solution(string ans, vector<int> v,int start) {
    if(v.size()==m) {
        if(s.insert(ans).second) {
            for(auto i:v) {
                cout<<i<<' ';
            }
            cout<<'\n';
        }
        return;
    }

    for(int i=start; i<n; i++) {
        v.push_back(arr[i]);
        solution(ans+" "+to_string(arr[i]),v,i);
        v.pop_back();
    }
}

void solve() {
    input();
    sort(arr,arr+n);
    solution("",{},0);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
