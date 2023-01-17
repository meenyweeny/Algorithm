//
// Created by 이경민 on 2023/01/17.
//
#include<iostream>
#include<vector>
using namespace std;

struct edge {
    int vertex;
    int weight;
};


vector<edge> graph[501];
int n,m;
int inf = 1e9;
long long dist[501];

void input() {
    cin>>n>>m;
    int a,b,c;
    while(m--) {
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
}

bool bellman() { //음의 사이클이 존재하면 false 반환
    //disf 배열을 전부 inf로 초기화
    fill(dist, dist+n+1, inf);

    dist[1] = 0; //첫 시작점의 최단거리 값을 0으로 만듦

    //n-1번 루프하면서 전체에 대한 최단거리를 찾음
    for(int i=0; i<n-1; i++) {

        //현재 정점의 index를 now로 하여, 정점 전체를 순회
        //숫자의 시작을 1로 하고 있음을 주의
        for(int now=1; now<=n; now++) {

            int len = graph[now].size();
            //현재 index의 인접 리스트에 대해 순회 시작
            for(int idx = 0; idx<len; idx++) {
                int next_vertex = graph[now][idx].vertex;
                int next_weight = graph[now][idx].weight;

                //현재 값이 inf가 아니면서(최소 한번 최단거리 갱신된 적이 있음을 뜻함)
                //최단거리가 갱신되는 경우(현재 최단거라 + cost가 기존 최단거리보다 작음)
                if(dist[now] != inf && dist[next_vertex] > dist[now] + next_weight) {
                    dist[next_vertex] = dist[now] + next_weight;
                }
            }
        }
    }

    //위 n-1회 루프가 끝나면, 마지막으로 한 번 더 순회하며
    //음수 사이클을 찾는다
    for(int now = 1; now <= n; now++) {
        int len = graph[now].size();
        for(int idx = 0; idx < len; idx++) {
            int next_vertex = graph[now][idx].vertex;
            int next_weight = graph[now][idx].weight;

            //n번째 루프에서 최단거리가 갱신되었다
            //--> 음의 사이클이 존재한다
            if(dist[now] != inf && dist[next_vertex] > dist[now] + next_weight) {
                return false;
            }
        }
    }

    return true;
}

void solve() {
    input();
    if(!bellman()) {
        cout<<-1;
    } else {
        for(int i=2; i<=n; i++) {
            if(dist[i] == inf) {
                cout<<-1;
            } else {
                cout<<dist[i];
            }
            cout<<'\n';
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
