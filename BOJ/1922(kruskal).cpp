//
// Created by 이경민 on 2023/01/16.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge {
    int start;
    int end;
    int weight;
};

vector<edge> edges;
int n,m,a,b,c;
int parent[1001];

bool comp(edge x, edge y) {
    return x.weight < y.weight;
}

void init() {
    for(int i=1; i<=n; i++) { //union find 초기화
        parent[i] = i;
    }
}

int find(int x) {
    if(parent[x] == x) {
        return x;
    } else {
        parent[x] = find(parent[x]);
        int result = parent[x];
        return result;
    }
}

bool merge(int x,int y) {
    int x_root = find(x);
    int y_root = find(y);

    if(x_root == y_root) {
        return true;
    } else {
        parent[x_root] = y_root;
        return false;
    }
}

void input() {
    cin>>n>>m;
    while(m--) {
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
}

void solution() {
    sort(edges.begin(), edges.end(), comp);

    init();

    int mst_cost = 0;
    int edge_count = 0;

    int edge_size = edges.size();
    edge tmp;
    for(int i=0; i<edge_size; i++) {
        tmp = edges[i];
        if(!merge(tmp.start, tmp.end)) {
            ++edge_count;
            mst_cost += tmp.weight;
        }

        if(edge_count == n - 1) {
            break;
        }
    }

    cout << mst_cost;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
