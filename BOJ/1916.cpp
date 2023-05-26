#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int inf = 2e9;

struct edge {
    int vertex;
    int weight;

    bool operator<(const edge & b) const {
        return weight < b.weight;
    }
};

int n,m,s,d;
vector<edge> graph[1001];
priority_queue<edge> pq;
int dist[1001];

void input() {
    cin>>n>>m;
    int v,u,w;
    for(int i=0; i<m; i++) {
        cin>>v>>u>>w;
        graph[v].push_back({u,w});
    }
    cin>>s>>d;
}

void solution() {
    fill(dist,dist+1001,inf);
    dist[s]=0;
    pq.push({s,0});

    while(!pq.empty()) {
        edge top = pq.top();
        pq.pop();

        if(top.weight>dist[top.vertex]) {
            continue;
        }

        int length = graph[top.vertex].size();
        for(int i=0; i<length; i++) {
            edge next = graph[top.vertex][i];

            if(dist[next.vertex] > top.weight+next.weight) {
                dist[next.vertex] = top.weight+next.weight;
                pq.push({next.vertex,dist[next.vertex]});
            }
        }
    }
    cout<<dist[d];
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
