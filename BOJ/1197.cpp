#include<iostream>
#include<vector>
using namespace std;

int v,e;
int arr[10001];
vector<pair<int,pair<int,int>>> edges;

int find(int x) {
    if(arr[x]==x) {
        return x;
    } else {
        return arr[x] = find(arr[x]);
    }
}

bool merge(int x,int y) {
    int xroot = find(x);
    int yroot = find(y);

    if(xroot!=yroot) {
        arr[xroot] = yroot;
        return false;
    } else {
        return true;
    }
}

void input() {
    cin>>v>>e;
    int a,b,c;
    while(e--) {
        cin>>a>>b>>c;
        edges.push_back({c,{a,b}});
    }
}

void solution() {
    for(int i=0; i<=v; i++) {
        arr[i] = i;
    }
    int answer = 0;
    sort(edges.begin(), edges.end());
    for(auto edge:edges) {
        if(merge(edge.second.first, edge.second.second)) {
            continue;
        } else {
            answer += edge.first;
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
}
