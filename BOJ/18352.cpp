//
// Created by 이경민 on 2023/01/25.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m,k,x;
vector<int> graph[300001];
int dist[300001];
const int inf = -1;

void input() {
    cin>>n>>m>>k>>x;
    int a,b;
    while(m--) {
        cin>>a>>b;
        graph[a].push_back(b);
    }
}

void solution() {
    fill(dist,dist+n+1,inf);

    queue<pair<int,int>> q;
    q.push({x,0});
    dist[x]=0;

    while(!q.empty()) {
        int front = q.front().first;
        int count = q.front().second;
        q.pop();

        int length = graph[front].size();
        for(int i=0; i<length; i++) {
            int next = graph[front][i];

            if(dist[next] != inf) {
                continue;
            }

            dist[next] = count + 1;
            q.push({next, count+1});
        }
    }

    vector<int> path;
    for(int i=1; i<=n; i++) {
        if(dist[i] == k) {
            path.push_back(i);
        }
    }

    if(path.empty()) {
        cout<<-1;
    } else {
        for(int i=0; i<path.size(); i++) {
            cout<<path[i]<<'\n';
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
