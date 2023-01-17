//
// Created by 이경민 on 2023/01/17.
//
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define INF 1987654321

struct edge {
    int vertex;
    int weight;

    bool operator<(const edge& b) const { //최소 힙 만들기 위한 연산자 오버로딩
        return weight > b.weight;
    }
};

int v,e,a,b,w,k;
int dist[20001];
vector<edge> adj[20001];
priority_queue<edge> pq;

void input() {
    cin>>v>>e>>k;
    while(e--) {
        cin>>a>>b>>w;
        adj[a].push_back({b, w});
    }
}

void solution() {
    for(int i=0; i<=v; i++) { //모든 정점에 대해 최단거리 무한대로 초기화
        dist[i] = INF;
    }

    pq.push({k,0}); //시작점을 큐에 넣고
    dist[k] = 0; //dist를 0으로 설정

    while(!pq.empty()) {
        edge top = pq.top();
        pq.pop();

        int now_vertex = top.vertex;
        int now_weight = top.weight;

        int len = adj[now_vertex].size();
        for(int i=0; i<len; i++) { //해당 정점에서 나가는 간선들을 전체 순회하며
            edge next = adj[now_vertex][i];

            //다음 갈 수 있는 정점들에 대해 최단거리를 계산
            //다음에 갈 점의 최단거리보다 지금 점 + 다음 점으로의 가중치가 더 작다면
            //최단거리를 갱신하고, 큐에 해당 지점을 넣음
            //방금 계산한 최단거리르 넣어야 함
            if(dist[next.vertex] > now_weight + next.weight) {
                dist[next.vertex] = now_weight + next.weight;
                pq.push({next.vertex, dist[next.vertex]});
            }
        }
    }

    for(int i=1; i<=v; i++) {
        if(dist[i]==INF) {
            cout<<"INF\n";
        } else {
            cout<<dist[i]<<'\n';
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
