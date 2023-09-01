#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int sz = 1e3 + 1;
int n,m;
int indegree[sz];
vector<int> graph[sz];
int semester[sz];

void input() {
    cin>>n>>m;
    int a,b;
    while(m--) {
        cin>>a>>b;
        graph[a].push_back(b);
        ++indegree[b];
    }
}

void solution() {
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(!indegree[i]) {
            q.push(i);
            semester[i] = 1;
        }
    }
    for(int i=0; i<n; i++) {
        if(q.empty()) {
            break;
        }
        int front = q.front();
        q.pop();

        for(auto g:graph[front]) {
            --indegree[g];
            semester[g] = max(semester[g],semester[front]+1);
            if(!indegree[g]) {
                q.push(g);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        cout<<semester[i]<<' ';
    }
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
