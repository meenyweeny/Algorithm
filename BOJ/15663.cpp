#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n,m;
int arr[10];
bool visited[10];
set<string> s;

void input() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
}

void solution(vector<int> v,string now) {
    if(v.size()==m) {
        if(s.insert(now).second) {
            for(auto i:v) {
                cout<<i<<' ';
            }
            cout<<'\n';
        }
        return;
    }

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            v.push_back(arr[i]);
            visited[i] = true;
            solution(v,now+" "+to_string(arr[i]));
            v.pop_back();
            visited[i] = false;
        }
    }
}

void solve() {
    input();
    sort(arr,arr+n);
    solution({},"");
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
