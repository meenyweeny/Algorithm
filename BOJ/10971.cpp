#include<iostream>
using namespace std;

int n, answer = 2e9;
int w[11][11];
bool visited[11];

void process(int before,int count,int sum) {
    if(count==n) {
        if(w[before][1]) {
            sum += w[before][1];
            answer = min(answer,sum);
        }
        return;
    }
    for(int i=2; i<=n; i++) {
        if(visited[i]) {
            continue;
        }
        if(!w[before][i]) {
            continue;
        }
        visited[i] = true;
        process(i,count+1,sum+w[before][i]);
        visited[i] = false;
    }
}

void solve() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>w[i][j];
        }
    }
    process(1,1,0);
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
