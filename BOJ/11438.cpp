//
// Created by 이경민 on 2023/01/18.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//MAX_K는 MAX_SIZE < 2^k가 될 수 있는 적당한 k값을 넣으면 된다
#define MAX_K 17
#define MAX_SIZE 100001

int n,m;
vector<vector<int>> graph;
int depth[MAX_SIZE];
int parent[MAX_K + 1][MAX_SIZE]; //dp를 위한 조상의 값
const int inf = -1;

//조상(parent, 부모노드의 값)과 depth 구하기
//사실상 dp를 동작하기 전 트리의 값을 초기화하는 역할에 가까움
void bfs(int node) {
    queue<int> q;
    q.push(node);

    //현재 depth와 조상의 root를 초기화한다
    depth[node] = 0;
    parent[0][node] = 1;

    //2^0 = 1
    //즉 그냥 1개의 depth씩 내려가면서, 부모/자식 노드 인덱스를 작성해둔다
    //2^0을 이용하여, 그 뒤 2^1 ~ 2^k까지 dp를 돌면서 해당 값을 저장해두는 것
    while(!q.empty()) {
        int front = q.front();
        q.pop();

        //노드의 자식들을 큐에 삽입한다
        int len = graph[front].size();
        for(int i=0; i<len; i++) {
            int front_child = graph[front][i]; //front의 자식(즉 인접 리스트에서 연결되어 있는 정점을 가져온다)

            //depth가 계산된 적이 없다면
            if(depth[front_child] == inf) {
                parent[0][front_child] = front; //자식노드 인덱스에 부모노드 인덱스 값을 넣어 부모를 찾아갈 수 있게 함
                depth[front_child] = depth[front] + 1; //depth 갱신(자식의 depth는 부모의 depth + 1이다)
                q.push(front_child); //자식을 큐에 삽입해, 자식의 자식(손자 노드)에 대해 부모값과 depth를 계산할 수 있게 한다
            }
        }
    }
}

//dp 점화식을 돌린다
//2^k = 2^(k-1) + 2^(k-1)
void dp(int node) {
    for(int k=1; k<MAX_K + 1; k++) {
        for(int i = 1; i<=node; i++) {
            parent[k][i] = parent[k-1][parent[k-1][i]];
        }
    }
}

int lca(int a, int b) {
    //1. a의 높이를 b와 맞춘다
    //b가 더 큼
    if(depth[a]<depth[b]) {
        for(int k=MAX_K; k>=0; k--) {
            if(a!=b && depth[parent[k][b]] >= depth[a]) {
                b = parent[k][b];
            }
        }
    } else if(depth[a]>depth[b]) { //a가 더 큼
        for(int k=MAX_K; k>=0; k--) {
            if(a!=b && depth[parent[k][a]] >= depth[b]) {
                a = parent[k][a];
            }
        }
    }

    //2. 높이가 같아지면 위로 2^k씩 올라가면서 공통 조상을 찾는다
    for(int k=MAX_K; k>=0; k--) {
        if(a!=b && parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }

    //두 노드가 같다면 a는 b의 조상
    return (a==b) ? a : parent[0][a];
}

void input() {
    cin>>n;
    graph.resize(n+1);
    int u,v;
    for(int i=1; i<n; i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void solve() {
    cin>>m;
    int u,v;
    fill(depth, depth + n + 1, inf);

    bfs(1);
    dp(n);

    while(m--) {
        cin>>u>>v;
        cout<<lca(u,v)<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solve();
}
