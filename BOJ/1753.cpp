#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct edge {
    int vertex;
    int weight;

    bool operator<(const edge& b) const {
        return weight > b.weight;
    }
};

int v,e,k;
const string inf_str = "INF";
const int inf = 2e9;
vector<edge> graph[20001];
int dist[20001];

void input() {
    cin>>v>>e;
    cin>>k;
    int u,v,w;
    for(int i=0; i<e; i++) {
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
}

void solution() {
    fill(dist,dist+20001,inf);

    priority_queue<edge> pq;
    pq.push({k,0});
    dist[k]=0;

    while(!pq.empty()) {
        edge top = pq.top();
        pq.pop();

        int now_vertex = top.vertex;
        int now_weight = top.weight;

        if(dist[now_vertex] < now_weight) {
            continue;
        }

        int length = graph[now_vertex].size();
        for(int i=0; i<length; i++) {
            edge next = graph[now_vertex][i];

            if(dist[next.vertex] > now_weight + next.weight) {
                dist[next.vertex] = now_weight + next.weight;
                pq.push({next.vertex, dist[next.vertex]});
            }
        }
    }

    for(int i=1; i<=v; i++) {
        if(dist[i]>=inf) {
            cout << inf_str;
        } else {
            cout<<dist[i];
        }
        cout<<'\n';
    }
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
