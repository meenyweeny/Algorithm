//
// Created by 이경민 on 2022/10/04.
//
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int n,m,v,a,b;
bool visited[1001];
vector<int> graph[1001];

void dfs(int x) {
    visited[x] = true;
    cout<<x<<" ";
    for(auto i:graph[x]) {
        if(visited[i]) {
            continue;
        }
        dfs(i);
    }
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        cout<<front<<" ";

        for(auto i:graph[front]) {
            if(visited[i]) {
                continue;
            }
            q.push(i);
            visited[i] = true;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>v;

    while(m--) {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout<<"\n";
    memset(visited,false,sizeof(visited));
    bfs(v);
}
