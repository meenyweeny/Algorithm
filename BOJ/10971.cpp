#include<iostream>
using namespace std;

int n;
int dist[11][11];
bool visited[11];
int answer = 2e9;

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>dist[i][j];
        }
    }
}

void solution(int before, int count, int length, bool visit[11]) {
    if(count==n) {
        if(dist[before][1]!=0) {
            length += dist[before][1];
            answer = min(answer,length);
        }
        return;
    }
    for(int j=2; j<=n; j++) {
        if(!visit[j] && dist[before][j]!=0) {
            visit[j] = true;
            length += dist[before][j];
            solution(j,count+1,length,visit);
            visit[j] = false;
            length -= dist[before][j];
        }
    }
}

void solve() {
    input();
    solution(1,1,0,visited);
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
