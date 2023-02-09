#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct edge {
    int vertex;
    int weight;

    bool operator<(const edge & b) const {
        return weight < b.weight;
    }
};

int n,e,u,v;
vector<edge> graph[801];
int dist[801];
const int inf = 2e9;

void input() {
    cin>>n>>e;
    int a,b,c;
    while(e--) {
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    cin>>u>>v;
}

void dijkstra(int start) {
    fill(dist, dist + 801, inf);
    dist[start] = 0;
    priority_queue<edge> pq;
    pq.push({start, 0});

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
                pq.push({next.vertex,dist[next.vertex]});
            }
        }
    }
}

void solution() {
    dijkstra(u);
    int su = dist[1];
    int uv = dist[v];
    int un = dist[n];
    dijkstra(v);
    int sv = dist[1];
    int vn = dist[n];

    unsigned long long case1,case2;
    if(su!=inf && uv!=inf && vn!=inf) {
        case1 = su+uv+vn;
    } else {
        case1 = inf;
    }

    if(sv!=inf && uv!=inf && un!=inf) {
        case2 = sv+uv+un;
    } else {
        case2 = inf;
    }

    unsigned long long answer = min(case1, case2);

    if(answer>=inf) {
        cout<<-1;
    } else {
        cout<<answer;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
