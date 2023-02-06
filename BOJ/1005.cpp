//
// Created by 이경민 on 2023/02/05.
//
#include<iostream>
#include<queue>
using namespace std;

int t,n,k,w;
const int sz = 1001;
int value[sz];
int newvalue[sz];
int indegree[sz];
vector<int> graph[sz];

void init() {
    fill(indegree, indegree + sz, 0);
    fill(value, value + sz, 0);
    for(int i=0; i<sz; i++) {
        graph[i].clear();
    }
}

void input() {
    cin>>n>>k;
    for(int i=1; i<=n; i++) {
        cin>>value[i];
    }
    int x,y;
    while(k--) {
        cin>>x>>y;
        graph[x].push_back(y);
        ++indegree[y];
    }
    cin>>w;
}

int solution() {
    queue<int> q;
    copy(value, value + sz, newvalue);
    for(int i=1; i<=n; i++) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }

    for(int i=0; i<n; i++) {
        if(q.empty()) {
            break;
        }
        int front = q.front();
        q.pop();

        int length = graph[front].size();
        for(int j=0; j<length; j++) {
            int next = graph[front][j];
            --indegree[next];
            newvalue[next] = max(newvalue[next], value[next] + newvalue[front]);
            if(indegree[next]==0) {
                q.push(next);
            }
        }
    }
    return newvalue[w];
}

void solve() {
    cin>>t;
    while(t--) {
        init();
        input();
        cout<<solution()<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
