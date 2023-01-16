//
// Created by 이경민 on 2023/01/16.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct edge {
    int end;
    int weight;

    bool operator<(const edge& b) const {
        return weight > b.weight;
    }
};

vector<edge> edges[1001];
bool visited[1001];
int n,m,a,b,c;

void input() {
    cin>>n>>m;
    while(m--) {
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
}

void solution() {
    priority_queue<edge> pq;
    pq.push({1,0});

    int result = 0;

    while(!pq.empty()) {
        edge top = pq.top();
        pq.pop();

        int now_end = top.end;
        int now_cost = top.weight;

        if(!visited[now_end]) {
            visited[now_end] = true;
            result += now_cost;

            for(int i=0; i<edges[now_end].size(); i++) {
                pq.push({edges[now_end][i].end, edges[now_end][i].weight});
            }
        }
    }

    cout<<result;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
