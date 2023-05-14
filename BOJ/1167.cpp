#include<iostream>
#include<vector>
using namespace std;

struct node {
    int x,weight;
};

int v;
const int maxsize = 100001;
vector<node> graph[maxsize];
int maxnode,maxdist;
bool visited[maxsize];

void input() {
    cin>>v;
    int u,w,d;
    for(int i=0; i<v; i++) {
        cin>>u;
        cin>>w;
        while(w!=-1) {
            cin>>d;
            graph[u].push_back({w,d});
            cin>>w;
        }
    }
}

void dfs(int vertex, int distance) {
    if(visited[vertex]) {
        return;
    }
    visited[vertex] = true;
    if(distance>maxdist) {
        maxdist = distance;
        maxnode = vertex;
    }
    for(auto k:graph[vertex]) {
        dfs(k.x,distance+k.weight);
    }
}

void solution() {
    dfs(1,0);
    fill(visited,visited+maxsize,false);
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
