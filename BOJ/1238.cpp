//
// Created by 이경민 on 2023/01/26.
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

int n,m,x;
int dist[1001];
int revdist[1001];
const int inf = 1e9;
vector<edge> graph[1001];
vector<edge> revgraph[1001];

void input() {
    cin>>n>>m>>x;
    int a,b,t;
    while(m--) {
        cin>>a>>b>>t;
        graph[a].push_back({b,t});
        revgraph[b].push_back({a, t});
    }
}

void dijkstra() {
    priority_queue<edge> pq;
    pq.push({x,0});
    dist[x] = 0;

    while(!pq.empty()) {
        edge top = pq.top();
        pq.pop();

        if(top.weight > dist[top.vertex]) {
            continue;
        }

        int length = graph[top.vertex].size();
        for(int i=0; i<length; i++) {
            edge next = graph[top.vertex][i];

            if(dist[next.vertex] > top.weight + next.weight) {
                dist[next.vertex] = top.weight + next.weight;
                pq.push({next.vertex, dist[next.vertex]});
            }
        }
    }
}

void revdijkstra() {
    priority_queue<edge> pq;
    pq.push({x,0});
    revdist[x] = 0;

    while(!pq.empty()) {
        edge top = pq.top();
        pq.pop();

        if(top.weight > revdist[top.vertex]) {
            continue;
        }

        int length = revgraph[top.vertex].size();
        for(int i=0; i<length; i++) {
            edge next = revgraph[top.vertex][i];

            if(revdist[next.vertex] > top.weight + next.weight) {
                revdist[next.vertex] = top.weight + next.weight;
                pq.push({next.vertex, revdist[next.vertex]});
            }
        }
    }
}

void solution() {
    fill(dist, dist+n+1, inf);
    fill(revdist, revdist + n + 1, inf);

    dijkstra();
    revdijkstra();

    int maxdist = -1;
    for(int i=1; i<=n; i++) {
        maxdist = max(dist[i] + revdist[i], maxdist);
    }
    cout<<maxdist;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
