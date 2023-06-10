#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
vector<int> graph[20001];
bool visited[20001];

void input() {
    cin>>n>>m;
    int u,v;
    while(m--) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void solution() {
    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1] = true;
    int max_vertex=1;
    int max_dist = 0;
    int max_count = 0;

    while(!q.empty()) {
        int front = q.front().first;
        int count = q.front().second;
        q.pop();

        if(count>max_dist) {
            max_vertex=front;
            max_dist=count;
            max_count=1;
        } else if(count==max_dist) {
            ++max_count;
            max_vertex = min(max_vertex,front);
        }

        for(auto v: graph[front]) {
            if(visited[v]) {
                continue;
            }
            visited[v]=true;
            q.push({v,count+1});
        }
    }

    cout<<max_vertex<<' '<<max_dist<<' '<<max_count;
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
