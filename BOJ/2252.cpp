//
// Created by 이경민 on 2023/01/16.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m,a,b;
vector<vector<int>> graph;
vector<int> indegree;

void input() {
    cin>>n>>m;

    //초기화
    graph.resize(n+1);
    for(int i=0; i<=n; i++) {
        indegree.push_back(0);
    }

    while(m--) {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        ++indegree[b]; //indegree 계산
    }
}

void solution() {
    queue<int> q;

    //위상정렬 시작
    //queue에 indegree가 0인 정점을 먼저 넣는다
    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    //완벽한 전체 순회를 위해 n개의 노드 반복
    for(int i=0; i<n; i++) {
        if(q.empty()) { //n개까지 전체 방문하기 전에 큐가 비었다면 사이클이 발생했다는 뜻
            break;
        }

        int front = q.front();
        q.pop();
        cout<<front<<" ";

        //방문한 정점에서 나가는 간선(outdegree)들에 대해 계산
        //해당 간선들이 들어오는 정점, 즉 도찯점에서는 들어오는 간선(indegree)이 줄어드는 것이기 때문에
        //간선 수만큼 indegree를 줄여주어야 한다
        for(int edge=0; edge<graph[front].size(); edge++) {
            int now_end = graph[front][edge];
            --indegree[now_end]; //도착점의 indegree를 1 빼준다

            //만약 indegree가 0이라면
            //다음 위상정렬 계산을 위해 해당 정점을 큐에 삽입한다
            if(indegree[now_end] == 0) {
                q.push(now_end);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
