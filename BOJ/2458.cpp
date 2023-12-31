#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
const int nodesize = 5e2 + 1;
vector<int> graph[nodesize];
vector<int> revgraph[nodesize];
bool visited[nodesize];

void input() {
    cin>>n>>m;
    int u,v;
    while(m--) {
        cin>>u>>v;
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }
}

int bfs(int start) {
    fill(visited, visited+nodesize, false);
    queue<int> q;
    q.push(start);
    int count = 0;
    visited[start] = true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(auto g:graph[front]) {
            if(visited[g]) {
                continue;
            }
            q.push(g);
            visited[g] = true;
            ++count;
        }
    }
    return count;
}

int revbfs(int start) {
    fill(visited, visited+nodesize, false);
    queue<int> q;
    q.push(start);
    int count = 0;
    visited[start] = true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(auto g:revgraph[front]) {
            if(visited[g]) {
                continue;
            }
            q.push(g);
            visited[g] = true;
            ++count;
        }
    }
    return count;
}

void solution() {
    int answer = 0;
    for(int i=1; i<=n; i++) {
        int count = bfs(i) + revbfs(i);
        if(count==n-1) {
            ++answer;
        }
    }
    cout<<answer;
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
    return 0;
}
