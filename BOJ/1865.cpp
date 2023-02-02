//
// Created by 이경민 on 2023/02/02.
//
#include<iostream>
#include<vector>
using namespace std;

struct edge {
    int vertex;
    int weight;
};

int tc,n,m,w;
vector<edge> graph[501];
int dist[501];
const int inf = 1987654321;

void initialize() {
    for(int i=0; i<=n; i++) {
        graph[i].clear();
    }
}

void input() {
    cin>>n>>m>>w;
    int s,e,t;
    while(m--) {
        cin>>s>>e>>t;
        graph[s].push_back({e,t});
        graph[e].push_back({s,t});
    }
    while(w--) {
        cin>>s>>e>>t;
        graph[s].push_back({e,-t});
    }
}

bool solution() {
    fill(dist, dist+n+1, inf);
    dist[1] = 0;

    for(int i=1; i<n; i++) {
        for(int now=1; now<=n; now++) {
            int length = graph[now].size();
            for(int j=0; j<length; j++) {
                edge next = graph[now][j];
                bool comp = dist[next.vertex] > next.weight + dist[now];
                if(comp) {
                    dist[next.vertex] = next.weight + dist[now];
                }
            }
        }
    }

    for(int now=1; now<=n; now++) {
        int length = graph[now].size();
        for(int j=0; j<length; j++) {
            edge next = graph[now][j];
            bool comp = dist[next.vertex] > next.weight + dist[now];
            if(dist[now] != inf && comp) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>tc;
    while(tc--) {
        input();
        solution() ? cout<<"NO" : cout<<"YES";
        cout<<'\n';
        initialize();
    }
}
