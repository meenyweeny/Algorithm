//
// Created by 이경민 on 2023/01/18.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int now) {
    if(visited[now]) { //방문한 정점이면 제외
        return;
    }
    visited[now] = true; //접근 시 방문 true 표시

    int len = graph[now].size();
    for(int i=0; i<len; i++) {
        int next = graph[now][i];

        if(!visited[next]) { //방문한 정점이면 제외
            dfs(next);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
}
