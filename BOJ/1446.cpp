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

int n,d;
vector<edge> graph[10001];
int dist[10001];
const int inf = 1e9;

void input() {
    cin>>n>>d;
    int a,b,c;
    while(n--) {
        cin>>a>>b>>c;
        if(b>d) {
            continue;
        }
        graph[a].push_back({b,c});
    }
}

void solution() {
    fill(dist,dist+d+1,inf);
    priority_queue<edge> pq;
    pq.push({0,0});

    while(!pq.empty()) {
        edge top = pq.top();
        pq.pop();

        if(top.weight > dist[top.vertex]) {
            continue;
        }

        int length = graph[top.vertex].size();
        for(int i=0; i<length; i++) {
            edge next = graph[top.vertex][i];

            if(dist[next.vertex] > next.weight + top.weight) {
                dist[next.vertex] = next.weight + top.weight;
                pq.push({next.vertex, dist[next.vertex]});
            }
        }
    }

    cout<<dist[d];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0; i<=9999; i++) {
        graph[i].push_back({i+1,1});
    }

    input();
    solution();
}
