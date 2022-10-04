//
// Created by 이경민 on 2022/10/04.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m,a,b;
vector<int> graph[101];
bool visited[101];

int bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int count = 0;

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ++count;

        for(auto i: graph[front]) {
            if(visited[i]) {
                continue;
            }
            q.push(i);
            visited[i] = true;
        }
    }

    return count-1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    while(m--) {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout<<bfs();
}
