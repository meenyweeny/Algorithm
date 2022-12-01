#include<iostream>
#include<vector>
using namespace std;

int n,answer;
int arr[21][21];

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>arr[i][j];
        }
    }
}

void run(vector<int> start,int front) {
    if(start.size()==(n/2)) {
        int s,l;
        s=l=0;
        int visited[21];
        fill(visited,visited+21,false);
        for(int i=0; i<start.size(); i++) {
            visited[start[i]] = true;
            for(int j=0; j<start.size(); j++) {
                s+=arr[start[i]][start[j]];
            }
        }
        for(int i=1; i<=n; i++) {
            if(visited[i]) {
                continue;
            }
            for(int j=1; j<=n; j++) {
                if(visited[j]) {
                    continue;
                }
                l+=arr[i][j];
            }
        }
        answer = min(answer,abs(s-l));
        return;
    }

    for(int i=front; i<=n; i++) {
        start.push_back(i);
        run(start,i+1);
        start.pop_back();
    }
}

void solution() {
    answer = 2e9;
    run({},1);
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
