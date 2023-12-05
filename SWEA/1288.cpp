#include<iostream>
using namespace std;
 
int answer;
unsigned long long num;
bool visited[10];
 
bool judge() {
    for(int i=0; i<10; i++) {
        if(!visited[i]) {
            return false;
        }
    }
    return true;
}
 
void solution() {
    int count = 1;
    fill(visited,visited+10,false);
    while(!judge()) {
        string s = to_string(num*count);
        for(auto c:s) {
            visited[c-'0'] = true;
        }
        ++count;
    }
    --count;
    answer = count * num;
}
 
void solve() {
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) {
        cin>>num;
        solution();
        cout<<'#'<<tc<<' '<<answer<<'\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    solve();
    return 0;
}
