//
// Created by 이경민 on 2023/01/25.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct edge {
    int vertex;
    int weight;

    bool operator<(const edge& b) const {
        return weight < b.weight;
    }
};

int n,m,u,v;
int dist[1001];
vector<edge> graph[1001];
priority_queue<edge> pq;
const int inf = 1987654321;

void input() {
    cin>>n>>m;
    int d;
    for(int i=0; i<m; i++) {
        cin>>u>>v>>d;
        graph[u].push_back({v,d});
//        graph[v].push_back({u,d});
    }
    cin>>u>>v;
}

void solution() {
    fill(dist, dist+n+1, inf);
    pq.push({u,0});
    dist[u] = 0;

    while(!pq.empty()) {
        edge top = pq.top();
        pq.pop();

        if(dist[top.vertex] < top.weight) {
            continue;
        }

        int length = graph[top.vertex].size();
        for(int i=0; i<length; i++) {
            edge next = graph[top.vertex][i];

            if(dist[next.vertex] > next.weight + top.weight) {
                dist[next.vertex] = next.weight + top.weight;
                pq.push({next.vertex, dist[next.vertex]});
            }
        }
    }
    cout<<dist[v];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
