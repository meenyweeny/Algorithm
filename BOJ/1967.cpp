#include<iostream>
#include<vector>
using namespace std;

struct Vertex {
    int x,weight;
};

int n;
vector<Vertex> graph[10001];
bool visited[10001];
int maxdist,maxnode;

void dfs(int node, int distance) {
    if(visited[node]) {
        return;
    }

    visited[node] = true;
    if(maxdist<distance) {
        maxnode=node;
        maxdist=distance;
    }

    for(auto i:graph[node]) {
        dfs(i.x,distance+i.weight);
    }
}

void input() {
    cin>>n;
    int u,v,d;
    for(int i=1; i<n; i++) {
        cin>>u>>v>>d;
        graph[u].push_back({v,d});
        graph[v].push_back({u,d});
    }
}

void solution() {
    dfs(1,0);
    fill(visited,visited+10001,false);
    dfs(maxnode,0);
    cout<<maxdist;
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
