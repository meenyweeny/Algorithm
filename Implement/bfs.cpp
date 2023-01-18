//
// Created by 이경민 on 2023/01/18.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true; //시작점에 대한 visited 처리

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        int len = graph[now].size();
        for(int i=0; i<len; i++) {
            int next = graph[now][i];

            if(!visited[next]) { //방문한 정점이면 제외
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
}
