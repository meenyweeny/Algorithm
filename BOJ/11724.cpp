//
// Created by 이경민 on 2022/10/13.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m,u,v;
vector<int> graph[1001];
bool visited[1001];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x]=true;

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(auto i:graph[front]){
            if(!visited[i]) {
                visited[i]=true;
                q.push(i);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    while(m--) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int answer = 0;
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            bfs(i);
            ++answer;
        }
    }
    cout<<answer;
}
