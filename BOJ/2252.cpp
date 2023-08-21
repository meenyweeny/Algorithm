#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int sz = 32000 + 1;
int n,m;
vector<int> graph[sz];
int indegree[sz];

void input() {
    cin>>n>>m;
    int a,b;
    while(m--) {
        cin>>a>>b;
        ++indegree[b];
        graph[a].push_back(b);
    }
}

void topology() {
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(!indegree[i]) {
            q.push(i);
        }
    }

    for(int i=1; i<=n; i++) {
        if(q.empty()) {
            return;
        }

        int front = q.front();
        cout<<front<<" ";
        q.pop();
        for(auto g:graph[front]) {
            --indegree[g];
            if(indegree[g]==0) {
                q.push(g);
            }
        }
    }
}

void solve() {
    input();
    topology();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
